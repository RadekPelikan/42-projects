/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_modif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:31:07 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 22:12:02 by rpelikan         ###   ########.fr       */
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
		ft_fill_left(result, details->size - (details->is_plus),
			FILL_ZERO_CHAR);
	else
		ft_resolve_space_filling(details, result);
}

void	ft_resolve_plus(t_sdetails *details, char **result)
{
	char	*plus_str;

	if (!details->is_plus)
		return ;
	plus_str = ft_alloc_str(2);
	ft_strlcpy(plus_str, "+", 3);
	ft_strappend_start(result, &plus_str);
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

void	ft_reolve_zero_hash_filling(t_sdetails *details, char **result)
{
	ft_fill_left(result, (details->size - 2 - (details->is_plus))
		* (details->size != 0), FILL_ZERO_CHAR);
	ft_appendhash(details, result);
}