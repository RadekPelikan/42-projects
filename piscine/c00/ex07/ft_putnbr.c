/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:39:13 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/09 09:40:03 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_digit(int num)
{
	ft_putchar(num + 48);
}

int	ft_pow(int base, int exp)
{
	int	out;
	int	i;

	out = base;
	i = 0;
	while (1)
	{
		if (exp == i)
			break ;
		out *= base;
		i++;
	}
	return (out);
}

int	ft_special_cond(int *nb)
{
	if (*nb < 0)
	{
		ft_putchar('-');
		*nb *= -1;
		return (0);
	}
	else if (*nb == 0)
	{
		ft_put_digit(0);
		return (1);
	}
	else
		return (0);
}

void	ft_putnbr(int nb)
{
	int	exponent;
	int	divider;
	int	prev;
	int	digit;

	if (ft_special_cond(&nb))
		return ;
	exponent = 0;
	while (1)
	{
		divider = ft_pow(10, exponent);
		if (nb / divider < 10)
			break ;
		exponent++;
	}
	prev = 0;
	while (1)
	{
		digit = (nb - prev) / divider;
		ft_put_digit(digit);
		prev += (digit * divider);
		divider /= 10;
		if (divider == 0)
			break ;
	}
}

// int	main(void)
// {
// 	ft_putnbr(123);
// 	ft_putchar('\n');
// 	ft_putnbr(-123);
// 	ft_putchar('\n');
// 	ft_putnbr(0);
// 	ft_putchar('\n');
// 	return 0;
// }