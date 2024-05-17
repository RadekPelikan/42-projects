/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:55:00 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/29 10:24:25 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = 0;
	return (dest);
}
/* 
int	main()
{
	char	*src = "Hello!";
	char	*dest = ft_strdup(src);
	printf("%s\n", dest);
	free(dest);
	printf("%s\n", dest);
}
 */