/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:59:35 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 19:54:04 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_helpers.h"

void	ft_fill_upto(char **src, char c, size_t len)
{
	char	*str_char;
	size_t	str_len;
	char	*char_fill;

	str_char = ft_alloc_str(1);
	if (*str_char)
		return;
	str_char[0] = c;
	str_len = ft_strlen(*src);
	char_fill = ft_alloc_str(len - str_len);
	if (*char_fill)
	{
		free(str_char);
		return;
	}
	char_fill = ft_strrepeat(str_char, len - str_len);
	free(str_char);
	*src = ft_strappend(src, &char_fill);
}