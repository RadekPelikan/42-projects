/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:54:10 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/26 21:58:12 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*ft_ltoa(long n)
{
	char	*ptr;
	int		len;

	len = ft_intlen(n);
	ptr = ft_alloc_str(len);
	if (n == LONG_MIN)
	{
		ptr[--len] = (n - 1) % 10 + '0' + 1;
		n /= 10;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[--len] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}

char	*ft_ultoa(unsigned long n)
{
	char	*ptr;
	int		len;

	len = ft_intlen(n);
	ptr = ft_alloc_str(len);
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[--len] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
