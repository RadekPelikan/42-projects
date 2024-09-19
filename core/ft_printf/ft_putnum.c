/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 04:03:41 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/19 20:48:31 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum(long n, char *chars)
{
	unsigned long	x;
	size_t			chars_len;
	int				result;

	chars_len = ft_strlen(chars);
	if (n < 0)
	{
		x = -n;
		ft_putchar('-');
	}
	else
		x = n;
	if (x >= chars_len)
	{
		result = ft_putnum(x / chars_len, chars);
		result += ft_putnum(x % chars_len, chars);
		return (result + (n < 0));
	}
	else
	{
		return (ft_putchar(chars[x]) + (n < 0));
	}
}

int	ft_put_unum(unsigned long n, char *chars)
{
	size_t			chars_len;
	int				result;

	chars_len = ft_strlen(chars);
	if (n >= chars_len)
	{
		result = ft_putnum(n / chars_len, chars);
		result += ft_putnum(n % chars_len, chars);
		return (result);
	}
	else
	{
		return (write(1, chars + n, 1));
	}
}
