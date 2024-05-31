/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:26:29 by rpelikan          #+#    #+#             */
/*   Updated: 2024/01/14 15:51:41 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'a';
// 	puts(&c);
// 	c = ft_toupper(c);
// 	puts(&c);
// 	c = 'z';
// 	puts(&c);
// 	c = ft_toupper(c);
// 	puts(&c);
// }
