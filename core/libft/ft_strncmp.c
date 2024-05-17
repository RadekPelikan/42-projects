/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:36:17 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/16 12:00:36 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
		return (0);
	while (*s1 == *s2 && --n && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// int	main()
// {
// 	char s1[] = "Hello";
// 	char s2[] = "aello";
// 	int n = 0;
// 	printf("%d\n", ft_strncmp(s1, s2, n));
// 	printf("%d\n", strncmp(s1, s2, n));
// 	return (0);
// }