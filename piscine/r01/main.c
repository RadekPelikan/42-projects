#include <stdio.h>
#include <stdlib.h>

int		ft_sqrt(int nb);
int		str_len(char *str);
char	*strip_spaces(char *str);
char	*char_to_values(char *str);
void	find_solution(char **board, int size);
void	put_board(char **board, int size);
void	put_nums(char *nums, int size);




int	main()
{
	char	input[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	// char	input[] = "4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2";
	// char	input[] = "1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4";
	char	**board;
	int		i;
	int		x;
	int		y;

	strip_spaces(input);
	char_to_values(input);

	if (str_len(input) % 4 != 0)
		return (0);

	char size = str_len(input) / 4 + 2;

	board = (char **) malloc(size * size);

	i = 0;
	while (i < size)
		board[i++] = (char *) malloc(size);

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			board[y][x] = 0;
			++x;
		}
		++y;
	}
	
	i = 0;
	while (i < size - 2)
	{
		board[0][i + 1] = input[i];
		board[size - 1][i + 1] = input[i + (size - 2)];
		board[i + 1][0] = input[i + 2 * (size - 2)];
		board[i + 1][size - 1] = input[i + 3 * (size - 2)];
		++i;
	}


	
	// char nums[6] = {1, 2, 3, 4, 5, 6};
	// permute(nums, 0, 5, 6);
	// printf("count: %d\n", count);
	find_solution(board, size);

	// put_board(board, size);
}