/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:34:35 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 17:58:06 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

// int	main(void)
// {
// 	char c = 'a';
// 	char str[40] = "a Hello a world!";

// 	printf("%lu\n", (unsigned long) &c);
// 	char *ptr = ft_strchr(str, c);
// 	puts(ptr);
// }