/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:46:44 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/29 12:59:41 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		x;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += (size - 1) * ft_strlen(sep);
	result = malloc(sizeof(char) * len + 1);
	x = 0;
	i = 0;
	while (i < size)
	{	
		ft_strcpy(result + x, strs[i]);
		if (i != size -1)
			ft_strcpy(result + x + ft_strlen(strs[i]), sep);
		x += ft_strlen(strs[i]) + ft_strlen(sep);
		++i;
	}
	result[len] = 0;
	return (result);
}

// int	main()
// {
// 	char *str_arr[3] = {
// 		"test1",
// 		"test223",
// 		"test3231150"
// 	};
// 	char *res = ft_strjoin(3, str_arr, " ");
// 	printf("%s\n", res);
// }
