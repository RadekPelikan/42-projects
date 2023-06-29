/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:18:25 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/08 15:15:20 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnumber(char num1, char num2, char num3)
{
	ft_putchar(num1);
	ft_putchar(num2);
	ft_putchar(num3);
	if (num1 != '7' || num2 != '8' || num3 != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	num1;
	char	num2;
	char	num3;

	num1 = '0';
	while (num1 <= '7')
	{
		num2 = num1 + 1;
		while (num2 <= '8')
		{
			num3 = num2 + 1;
			while (num3 <= '9')
			{
				ft_putnumber(num1, num2, num3);
				num3++;
			}
			num2++;
		}
		num1++;
	}
}

// int main(){
// 	ft_print_comb();
// }
