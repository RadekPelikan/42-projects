/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:55:26 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 17:58:27 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int) ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char c = 'a';
// 	char str[40] = "a Hello a world!";

// 	printf("%lu\n", (unsigned long) &c);
// 	char *ptr = ft_strrchr(str, c);
// 	puts(ptr);
// }