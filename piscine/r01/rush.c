#include <stdio.h>
#include <stdlib.h>

void	put_nums(char *nums, int size);
void	find_max(int x, int y, int max);
void	put_board(char **board, int size);


char	**g_board;
int		g_size;
int		g_x;
int		g_y;


int		a = 0;
int		b = 0;

int		includes(char *arr, char c)
{
	int	i;
	while (i < g_size - 2)
	{
		if(arr[i] == c)
			return (0);
		++i;
	}
	return(1);
}

int		get_side(int x, int y)
{
		int	side;

	// top row
	if (y == 0)
		side = 0;
	// right col
	else if (x == g_size - 1)
		side = 1;
	// bottom row
	else if (y == g_size - 1)
		side = 2;
	// left col
	else if (x == 0 )
		side = 3;
	return (side);
}

int		get_g_side()
{
	return (get_side(g_x, g_y));
}

int		is_board_valid()
{
	int		i;
	int		j;
	int		k;
	int		count;
	int		prev;
	// check if the the number of seen towers is correct, only for the g_x and g_y
	
	prev = 0;
	count = 0;
	i = 0;
	while (i < g_size - 2)
	{
		if (get_g_side() == 0 && prev < g_board[i + 1][g_x])
		{
			prev = g_board[i + 1][g_x];
			++count;
		}
		else if (get_g_side() == 1 && prev < g_board[g_y][i + 1])
		{
			prev = g_board[g_y][i + 1];
			++count;
		}
		else if (get_g_side() == 2 && prev < g_board[i + 1][i])
		{
			prev = g_board[i + 1][i];
			++count;
		}
		else if (get_g_side() == 3 && prev < g_board[g_y][i + 1])
		{
			prev = g_board[g_y][i + 1];
			++count;
		}
		++i;
	}

	if (count != g_board[g_y][g_x])
		return (0);

	// check if the numbers are not repeating per row and pre column
	
	// repeating per rows
	i = 1;
	while (i < g_size - 2)
	{
		j = 1;
		while (j < g_size - 2)
		{
			k = j + 1;
			while (k < g_size - 2)
			{
				if (g_board[i][j] == g_board[i][k] && g_board[i][j] && g_board[i][k])
					return (0);
				++k;
			}
			++j;
		}
		++i;
	}
	
	// repeating per columns
	i = 0;
	i = 1;
	while (i < g_size - 2)
	{
		j = 1;
		while (j < g_size - 2)
		{
			k = j + 1;
			while (k < g_size - 2)
			{
				if (g_board[j][i] == g_board[k][i] && g_board[j][i] && g_board[k][i])
					return (0);
				++k;
			}
			++j;
		}
		++i;
	}

	return (1);
}

void	swap(char* x, char* y)
{
	char temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	reset_line(char *prev, int x, int y)
{
	int	i;

	i = 0;
	while (i < g_size - 2)
	{
		if (get_side(x, y) == 0)
		{
			g_board[i + 1][g_x] = prev[i];
		}
		else if (get_side(x, y) == 1)
		{
			g_board[g_y][i + 1] = prev[i];
		}
		else if (get_side(x, y) == 2)
		{
			 g_board[i + 1][i] = prev[i];
		}
		else if (get_side(x, y) == 3)
		{
			g_board[g_y][i + 1] = prev[i];
		}
		++i;
	}
}

int	permute(char *nums, int l, int r)
{
	int		i;
	int		_x;
	int		_y;
	char	*prev;

	if (l == r)
	{
		_x = g_x;
		_y = g_y;
		prev = (char *) malloc(g_size - 2);
		i = 0;
		while (i < g_size - 2)
		{
			if (get_g_side() == 0)
			{
				prev[i] = g_board[i + 1][g_x];
			}
			else if (get_g_side() == 1)
			{
				prev[i] = g_board[g_y][i + 1];
			}
			else if (get_g_side() == 2)
			{
				prev[i] = g_board[i + 1][i];
			}
			else if (get_g_side() == 3)
			{
				prev[i] = g_board[g_y][i + 1];
			}
			++i;
		}
		i = 0;
		// put_nums(nums, g_size - 2);
		while (i < g_size - 2)
		{
			if (get_g_side() == 0 && (nums[i] == g_board[i + 1][g_x] || g_board[i + 1][g_x] == 0))
			{
				g_board[i + 1][g_x] = nums[i];
			}
			else if (get_g_side() == 1 && (nums[i] == g_board[g_y][i + 1] || g_board[g_y][i + 1] == 0))
			{
				g_board[g_y][i + 1] = nums[i];
			}
			else if (get_g_side() == 2 && (nums[i] == g_board[i + 1][i] || g_board[i + 1][i] == 0))
			{
				g_board[i + 1][i] = nums[i];
			}
			else if (get_g_side() == 3 && (nums[i] == g_board[g_y][i + 1] || g_board[g_y][i + 1] == 0))
			{
				g_board[g_y][i + 1] = nums[i];
			}
			else
			{
				// printf("overlapping numbers!\n");
				reset_line(prev, _x, _y);
				return -1;
			}
			++i;
		}
		// check if the board is valid

		if (!is_board_valid())
		{
			printf("Board not valid!\n");
			// put_board(g_board, g_size);
			reset_line(prev, _x, _y);
			return (-1);
		}

		printf("move on\n");
		find_max(g_x, g_y, g_board[g_y][g_x]);
	}
    else
	{
		i = l;
        while (i <= r) {
            swap((nums + l), (nums + i));
			// printf("i: %d | r: %d\n", i, r);
            int out = permute(nums, l + 1, r);
			// invalid placement, so do another permute
			if (out == -1)
			{
			}
			swap((nums + l), (nums + i)); // backtrack
			++i;
        }
    }
	return (0);
}


void	find_max(int x, int y, int max)
{
	// find the biggest value in the sides, that is not solved
	b = 0;
	if (a == 20)
		return ;
	a++;

	int	i;
	int	_x;
	int	_y;
	int	side;
	int	_max;

	if (max == 0)
		return ;

	// printf("Max here: %d\n", max);	

	// starting position for finding the hightest number

	// top row
	if (y == 0 && 0 <= x && x < g_size - 1)
		i = x + 1;
	// right col
	else if (x == g_size - 1 && 0 <= y && y < g_size - 1)
		i = y + 1;
	// bottom row
	else if (y == g_size - 1 && 0 <= x && x < g_size - 1)
		i = x + 1;
	// left col
	else if (x == 0 && 0 <= y && y < g_size - 1)
		i = y + 1;

	side = 0;
	_max = 0;
	while (side < 4)
	{
		// printf("i: %d | side: %d\n", i, side);
		// top row
		if (side == 0 && _max < g_board[0][i] && g_board[0][i] <= max)
		{
			_x = i;
			_y = 0;
			_max = g_board[0][i];
		}
		// right col
		if (side == 1 && _max < g_board[i][g_size - 1] && g_board[i][g_size - 1] <= max)
		{
			_x = g_size - 1;
			_y = i;
			_max = g_board[0][i];
		}
		// bottom row
		if (side == 2 && _max < g_board[0][g_size - 1] && g_board[0][g_size - 1] <= max)
		{
			_x = g_size - 1;
			_y = 0;
			_max = g_board[0][i];
		}
		// left col
		if (side == 3 && _max < g_board[i][0] && g_board[i][0] <= max)
		{
			_x = 0;
			_y = i;
			_max = g_board[0][i];
		}
		if (i % (g_size - 2) == 0)
		{
			i = 0;
			++side;
		}
		++i;
	}

	if (_x == x && _y == y)
	{
		x = 0;
		y = 0;
		--max;
		find_max(x, y, max);	
		return ;
	}
	else
	{
		put_board(g_board, g_size);
	}

	g_x = _x;
	g_y = _y;

	printf("_max: %d | _x: %d | _y: %d\n", _max, _x, _y);
	// when found try each combination of values that could work for solution

	char	*nums;
	int		index;

	nums = malloc(4 * g_size);
	
	i = 0;
	while (i < g_size - 2)
	{
		nums[i] = i + 1;
		++i;
	}

	put_nums(nums, g_size - 2);

	permute(nums, 0, g_size - 3);
	// put_nums(nums, size - 2);
	

	// if it works, call this funciton again, an make it recursive

	// check if all cells are filled and if the solution is correct

}

void	find_solution(char **board, int size)
{
	g_board = board;
	g_size = size;
	g_x = 0;
	g_y = 0;
	find_max(0, 0, size - 2);
}