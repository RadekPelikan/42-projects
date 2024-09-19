/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 01:52:43 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/19 20:49:55 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_processparam(va_list args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, uintptr_t)));
	if (c == 'd' || c == 'i')
		return (ft_putdecnum(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunsignednum(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putlowerhex(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_putupperhex(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			size += ft_processparam(args, format[++i]);
		}
		else
		{
			size += ft_putchar(format[i]);
		}
		++i;
	}
	va_end(args);
	return (size);
}
