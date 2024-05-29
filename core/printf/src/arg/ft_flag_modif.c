/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_modif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:31:07 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 21:31:26 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_helpers.h"

void	ft_resolve_space_filling(t_sdetails *details, char **result)
{
	if (details->is_minus)
		ft_fill_right(result, details->size, FILL_SPACE_CHAR);
	else
		ft_fill_left(result, details->size, FILL_SPACE_CHAR);
}

void	ft_resolve_zero_filling(t_sdetails *details, char **result)
{
	if (details->is_zero && !details->is_minus)
		ft_fill_left(result, details->size, FILL_ZERO_CHAR);
	else
		ft_resolve_space_filling(details, result);
}

void	ft_appendhash(t_sdetails *details, char **result)
{
	char	*hash_str;

	if (!details->is_hash)
		return ;
	hash_str = ft_alloc_str(2);
	ft_strlcpy(hash_str, "0x", 3);
	ft_strappend_start(result, &hash_str);
}
