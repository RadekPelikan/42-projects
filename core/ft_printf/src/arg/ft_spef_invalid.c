/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spef_invalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:32:43 by rpelikan          #+#    #+#             */
/*   Updated: 2024/06/01 15:55:48 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_resolve_spef_invalid_dot(const char *format, t_sdetails *details)
{
	char	*result;
	char	*zero;

	if (details->float_size != 0)
	{
		ft_errputstr("Invalid state\nft_resolve_spef_invalid_dot: float_size != 0\n");
		return (NULL);
	}
	result = ft_calloc(sizeof(char), details->index_spef + 2);
	ft_strlcpy(result, format - 1, details->index_spef + 2);
	zero = ft_calloc(sizeof(char), 3);
	zero[0] = '0';
	zero[1] = details->specifier;
	zero[2] = '\0';
	ft_strappend(&result, &zero);
	return (result);
}

char	*ft_resolve_spef_invalid(const char *format, t_sdetails *details)
{
	char	*result;

	if (!details->is_invalid)
	{
		ft_errputstr("Invalid state\nft_resolve_spef_invalid: is_invalid == true\n");
		return (NULL);
	}
	result = ft_substr(format - 1, 0, details->index_spef + 2);
	return (result);
}