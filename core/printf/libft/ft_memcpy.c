/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:15:18 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 19:00:40 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*d;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	d = dst;
	i = 0;
	while (n > i)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (d);
}

// int main(void){
//	char str[40] = "Hello world, how are you?";
//	char dest[40];
//
//	puts(str);
//	ft_memcpy(dest, str, 10);
//	puts(dest);
//}