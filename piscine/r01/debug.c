#include <stdio.h>

int		ft_sqrt(int nb);
int		str_len(char *str);
void	put_char(char c);

void	print_board_debug(char *str, int size)
{
	int		i;

	size += 2;
	i = 0;
	while (i < size * size)
	{
		do
		{
			put_char(*(str + i) + '0');
			++i;
		}
		while (i % 6 != 0);
		put_char('\n');
	}
}