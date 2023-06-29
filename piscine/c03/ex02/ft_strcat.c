/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:50:05 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/15 18:23:33 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		dest_end;

	i = 0;
	dest_end = 0;
	while (*(dest + dest_end))
		++dest_end;
	while (*(src + i))
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
// 	printf("%s\n", ft_strcat(dest1, src1));
// 	printf("%s\n", strcat(dest2, src2));
// 	return (0);
// }