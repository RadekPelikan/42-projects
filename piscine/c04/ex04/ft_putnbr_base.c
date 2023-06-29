/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:57:10 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/20 14:31:57 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base)
{
	int	_base;

	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nbr = 147483648;
	}
	_base = 0;
	while (base[_base])
		_base++;
	if (_base < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= _base)
		ft_putnbr_base(nbr / _base, base);
	write(1, &base[nbr % _base], 1);
}
/* 
int	main()
{
	int	nbr;
	char	*base;

	nbr = 123456789;
	base = "0123456789abcdef";
	// printf("%c\n", base[(nbr / 16 / 16 / 16) % 16]);
	ft_putnbr_base(nbr, base);
	return (0);
}
 */