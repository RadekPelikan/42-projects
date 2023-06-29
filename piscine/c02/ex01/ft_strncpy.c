/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:02:03 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/15 17:27:47 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src && n)
	{
		*(dest + i++) = *src++;
		--n;
	}
	while (n--)
		*(dest + i++) = '\0';
	return (dest);
}

// int	main()
// {
// 	char src0[] = "ABCDEFGH";
// 	char src1[] = "ABCDEFGH";
// 	char dest0[] = "abc";
// 	char dest1[] = "abc";
// 	int	n = 100;

// 	printf("Source0: %s\n", src0);
// 	printf("Expect: %s\n", strncpy(dest0, src0, n));
// 	printf("Source1: %s\n", src1);
// 	printf("Result: %s\n", ft_strncpy(dest1, src1, n));
// }