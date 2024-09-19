/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 04:02:42 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/19 20:48:51 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t ptr)
{
	int		size;

	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	size = ft_putstr("0x");
	size += ft_put_unum(ptr, HEX_CHARS_LOWER);
	return (size);
}
