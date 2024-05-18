/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:32:17 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 18:11:40 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	m;

	len = ft_intlen(n);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	m = n;
	if (m < 0)
	{
		ptr[0] = '-';
		m *= -1;
	}
	ptr[len] = '\0';
	len--;
	if (m == 0)
		ptr[0] = '0';
	while (m)
	{
		ptr[len] = m % 10 + '0';
		m /= 10;
		len--;
	}
	return (ptr);
}
