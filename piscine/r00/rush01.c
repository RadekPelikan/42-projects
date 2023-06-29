/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:56:28 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/11 09:31:00 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	my_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] != '\0')
		res = res * 10 + str[i++] - '0';
	return (sign * res);
}

void	print_element(int x, int y, int curr_x, int curr_y)
{
	if ((curr_x == 0 && curr_y == 0)
		|| (curr_x == x - 1 && curr_y == y - 1))
		ft_putchar('/');
	else if ((curr_x == x - 1 && curr_y == 0)
		|| (curr_x == 0 && curr_y == y - 1))
		ft_putchar('\\');
	else if (curr_x == 0 || curr_x == x - 1
		|| curr_y == 0 || curr_y == y - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	curr_x;
	int	curr_y;

	if (x <= 0 || y <= 0 || x >= 210 || y >= 10000)
		return ;
	curr_y = 0;
	while (curr_y < y)
	{
		curr_x = 0;
		while (curr_x < x)
		{
			print_element(x, y, curr_x, curr_y);
			curr_x++;
		}
		ft_putchar('\n');
		curr_y++;
	}
}
