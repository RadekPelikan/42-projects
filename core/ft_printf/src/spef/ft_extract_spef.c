/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_spef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:05:11 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/31 20:48:56 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

// Returns the number of characters than were extracted from the format
size_t	ft_extr_num(unsigned int *size, const char *format, size_t len)
{
	char	*extracted_num;

	extracted_num = ft_calloc(sizeof(char), len + 1);
	ft_strlcpy(extracted_num, format, len + 1);
	*size = (unsigned int)ft_atoi(extracted_num);
	free(extracted_num);
	return (len);
}

void	ft_extr_sizes(t_sdetails *details, const char *format, size_t spef_len)
{
	size_t index_end;

	index_end = details->index_dot;
	if (details->is_dot)
		index_end = details->index_dot;
	else
		index_end = spef_len;
	ft_extr_num(&details->size, format + details->index_size, index_end
		- details->index_size);
	ft_extr_num(&details->float_size, format + index_end + 1, spef_len
		- index_end);
}