/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:29:42 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/09 09:26:03 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_number_b(char num_a_0, char num_a_1, char num_b_0, char num_b_1)
{
	while (num_b_0 <= '9')
	{
		if (num_a_0 != num_b_0)
		{
			num_b_1 = '0';
		}
		while (num_b_1 <= '9')
		{
			ft_putchar(num_a_0);
			ft_putchar(num_a_1);
			ft_putchar(' ');
			ft_putchar(num_b_0);
			ft_putchar(num_b_1);
			if (num_a_0 != '9' || num_a_1 != '8')
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			num_b_1++;
		}
		num_b_0++;
	}
}

void	ft_print_comb2(void)
{
	char	num_a_0;
	char	num_a_1;
	char	num_b_0;
	char	num_b_1;

	num_a_0 = '0';
	while (num_a_0 <= '9')
	{
		num_a_1 = '0';
		while (num_a_1 <= '9')
		{
			num_b_0 = num_a_0;
			num_b_1 = num_a_1 + 1;
			if (num_b_1 < '9')
			{
				num_b_1 = '0';
				num_b_0++;
			}
			ft_number_b(num_a_0, num_a_1, num_b_0, num_b_1);
			num_a_1++;
		}
		num_a_0++;
	}
}

// int	main()
// {
// 	ft_print_comb2();
// 	return 0;
// }