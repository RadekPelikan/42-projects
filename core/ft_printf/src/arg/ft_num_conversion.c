/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:36:06 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/31 20:49:08 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

size_t	ft_hexlen(unsigned long n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= 16;
		++len;
	}
	return (len);
}

char	*ft_ultohex(unsigned long n)
{
	char	*result;
	size_t	len;

	len = ft_hexlen(n);
	result = ft_alloc_str(len);
	if (n == 0)
		result[0] = '0';
	result[len--] = '\0';
	while (n)
	{
		if (n % 16 < 10)
			result[len] = n % 16 + '0';
		else
			result[len] = n % 16 + 'a' - 10;
		n /= 16;
		--len;
	}
	return (result);
}

static size_t	ft_ulstrlen(unsigned long n, unsigned int divisor)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= divisor;
		++len;
	}
	return (len);
}

char	*ft_ultostr(unsigned long n, const char *chars)
{
	char	*result;
	size_t len;
	unsigned int divisor;

	if (!*chars)
		return (NULL);
	divisor = ft_strlen(chars);
	len = ft_ulstrlen(n, divisor);
	result = ft_alloc_str(len);
	if (n == 0)
		result[0] = chars[0];
	result[len--] = '\0';
		while (n)
	{
		result[len] = chars[n % divisor];
		n /= divisor;
		--len;
	}
	return (result);
}
