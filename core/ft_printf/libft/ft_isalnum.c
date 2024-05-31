/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:35:59 by rpelikan          #+#    #+#             */
/*   Updated: 2024/02/03 18:15:30 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	is_lower;
	int	is_upper;
	int	is_digit;

	is_lower = (c >= 'a' && c <= 'z');
	is_upper = (c >= 'A' && c <= 'Z');
	is_digit = (c >= '0' && c <= '9');
	if (is_lower || is_upper || is_digit)
	{
		return (1);
	}
	return (0);
}
