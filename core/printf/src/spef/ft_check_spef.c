/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spef.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:59:10 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/26 21:15:13 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_helpers.h"

bool	ft_is_start_flag(char c)
{
	return (c == FLAG_MINUS || c == FLAG_HASH || c == FLAG_SPACE
		|| c == FLAG_PLUS);
}

void	ft_enable_start_flag(t_sdetails *details, char c)
{
	if (c == FLAG_MINUS)
		details->is_minus = true;
	else if (c == FLAG_ZERO)
		details->is_zero = true;
	else if (c == FLAG_HASH)
		details->is_hash = true;
	else if (c == FLAG_SPACE)
		details->is_space = true;
	else if (c == FLAG_PLUS)
		details->is_plus = true;
}

bool	ft_check_start_flag(const char spef_c, t_sdetails *details, size_t i)
{
	bool	is_number;

	is_number = ft_isdigit(spef_c);
	if (!details->is_flag_set && (ft_is_start_flag(spef_c)
			|| ((details->index_size != 0 || !details->is_dot)
				&& spef_c == FLAG_ZERO)))
		ft_enable_start_flag(details, spef_c);
	if (!details->is_flag_set && !details->is_dot && is_number)
	{
		details->is_flag_set = true;
		details->index_size = i;
	}
	else if (details->is_flag_set && ft_is_start_flag(spef_c))
	{
		details->is_invalid = true;
		return (true);
	}
	return (false);
}

bool	ft_check_dot_spef(const char spef_c, t_sdetails *details, size_t i)
{
	bool	is_specifier_char;
	bool	is_number;

	is_specifier_char = ft_stringcludes(SPECIFIER_CHARS, spef_c);
	is_number = ft_isdigit(spef_c);
	if (spef_c == FLAG_DOT && !details->is_dot)
	{
		details->is_dot = true;
		details->index_dot = i;
		return (false);
	}
	if (details->is_dot && (!is_specifier_char && !is_number))
	{
		details->is_dot_invalid = true;
		return (true);
	}
	return (false);
}

// Validates the specifier
// If it encounters an invalid character or sequence of characters then it returns
// Sets invalid attributes in t_sdetails
// Returns (bool) if specifier is finished
bool	ft_check_specifier(const char spef_c, t_sdetails *details, size_t i)
{
	bool	is_specifier_char;
	bool	is_number;

	is_specifier_char = ft_stringcludes(SPECIFIER_CHARS, spef_c);
	is_number = ft_isdigit(spef_c);
	if (!is_specifier_char && !is_number && !ft_is_start_flag(spef_c)
		&& spef_c != FLAG_ZERO && spef_c != FLAG_DOT && !details->is_dot)
	{
		details->is_invalid = true;
		return (true);
	}
	if (is_specifier_char)
		return (true);
	if (ft_check_start_flag(spef_c, details, i))
		return (true);
	if (ft_check_dot_spef(spef_c, details, i))
		return (true);
	return (false);
}