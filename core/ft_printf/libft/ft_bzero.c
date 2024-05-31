/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:03:16 by rpelikan          #+#    #+#             */
/*   Updated: 2024/01/14 15:50:46 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*ptr = '\0';
		++ptr;
		++i;
	}
}

//int	main(void)
//{
//	char	str[50] = "Hello World!";
//
//	puts(str);
//	ft_bzero(str, 4);
//	puts(str);
//}
