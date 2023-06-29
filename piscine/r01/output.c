#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb);
int	str_len(char *str);

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_nums(char *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_char(*(nums + i) + '0');
		++i;
	}
	put_char('\n');
}

void	putn_str(char *str, int size)
{
	int	i;
	if (size == -1)
		size = str_len(str);
	write(1, str, size);
}

void	put_str(char *str)
{
	putn_str(str, -1);
}

void	put_board(char **board, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_char(board[y][x] + '0');
			put_char(' ');
			++x;
		}
		put_char('\n');
		++y;
	}
}