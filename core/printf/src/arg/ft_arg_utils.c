/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:59:35 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 20:43:49 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_helpers.h"

void	ft_fill_upto(char **src, size_t len, char c)
{
	size_t	str_len;
	char	*char_fill;

	str_len = ft_strlen(*src);
	char_fill = ft_charrepeat(c, len - str_len);
	if (!*char_fill)
		return;
	ft_strappend(src, &char_fill);
}