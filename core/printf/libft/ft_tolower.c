/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:32:26 by rpelikan          #+#    #+#             */
/*   Updated: 2024/01/14 15:51:39 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}

// int	main(void)
// {
// 	char c = 'A';

// 	puts(&c);
// 	c = ft_tolower(c);
// 	puts(&c);

// 	c = 'Z';
// 	puts(&c);
// 	c = ft_tolower(c);
// 	puts(&c);
// }