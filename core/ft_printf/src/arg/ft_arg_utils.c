/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:59:35 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 20:50:52 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_helpers.h"

void	ft_fill_left(char **src, size_t len, char c)
{
	size_t	str_len;
	char	*char_fill;

	str_len = ft_strlen(*src);
	if (str_len > len)
		return ;
	char_fill = ft_charrepeat(c, len - str_len);
	if (!*char_fill)
		return ;
	ft_strappend(&char_fill, src);
	*src = char_fill;
}

void	ft_fill_right(char **src, size_t len, char c)
{
	size_t str_len;
	char *char_fill;

	str_len = ft_strlen(*src);
	if (str_len > len)
		return ;
	char_fill = ft_charrepeat(c, len - str_len);
	if (!*char_fill)
		return ;
	ft_strappend(src, &char_fill);
}