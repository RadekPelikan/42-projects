/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:36:34 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/15 18:26:12 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		i;
	int		dest_end;

	i = 0;
	dest_end = 0;
	while (*(dest + dest_end))
		++dest_end;
	while (*(src + i) && nb--)
	{
		*(dest + dest_end) = *(src + i);
		++i;
		++dest_end;
	}
	*(dest + dest_end) = '\0';
	return (dest);
}

// int	main()
// {
// 	char dest1[100] = "Hello";
// 	char dest2[100] = "Hello";
// 	char src1[] = "World";
// 	char src2[] = "World";
// 	printf("%s\n", ft_strncat(dest1, src1, 0));
// 	printf("%s\n", strncat(dest2, src2, 0));
// 	return (0);
// }
