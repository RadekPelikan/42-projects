/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:47:15 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 18:40:09 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!dest && !src)
		return (0);
	i = 0;
	if ((size_t)dest - (size_t)src < n)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str1[40] = "123456.....";
// 	char	*from;
// 	char	*to;

// 	from = str1;
// 	to = str1 + 3;
// 	printf("From: %lu\n", (unsigned long)from);
// 	printf("To: %lu\n", (unsigned long)to);
// 	puts(str1);
// 	ft_+memmove(to, from+2, 3);
// 	puts(str1);
// }
