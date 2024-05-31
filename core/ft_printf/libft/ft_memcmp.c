/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:30:00 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 18:28:54 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = s1;
	p2 = s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char str1[40] = "Hello a world!";
// 	char str2[40] = "Hello b world!";

// 	int res = ft_memcmp(str1, str2, 5);
// 	printf("%d\n", res);

// 	res = memcmp(str1, str2, 5);
// 	printf("%d\n", res);
// }