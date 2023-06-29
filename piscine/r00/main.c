/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:56:34 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/11 09:35:15 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	rush(int x, int y);
int		my_atoi(char *str);

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc == 1)
	{
		x = 10;
		y = 10;
	}
	else if (argc == 2)
	{
		x = my_atoi(argv[1]);
		y = 10;
	}
	else if (argc == 3)
	{
		x = my_atoi(argv[1]);
		y = my_atoi(argv[2]);
	}
	else
	{
		ft_putstr("Too many parameters");
		return (1);
	}
	rush(x, y);
	return (0);
}
