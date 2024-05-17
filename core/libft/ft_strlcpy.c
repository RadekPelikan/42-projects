/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:31:07 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/15 17:28:08 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		len;

	len = 0;
	while (*(src + len) && --size)
		*dest++ = *(src + len++);
	*dest = '\0';
	while (*(src + len))
		++len;
	return (len);
}

// int	main()
// {
// 	// char	str1[] = "hghhhhhhhhhhhhhhhhhhhhhhhhhhhh";
// 	char	str2[100];
// 	int		size = 100;

// 	int a = ft_strlcpy(str2, "hdgdfgdfg", size);
// 	printf("%s\n", str2);
// 	char	str3[100];
// 	int b = strlcpy(str3, "hdgdfgdfg", size);
// 	printf("%s\n", str2);

// 	printf("A: %d | B: %d", a ,b);
// }