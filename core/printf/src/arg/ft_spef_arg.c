/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spef_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:58:11 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 21:51:58 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_helpers.h"

char	*ft_resolve_spef_char(t_sdetails *details, char c)
{
	char	*result;

	(void)details;
	result = ft_calloc(sizeof(char), 2);
	result[0] = c;
	result[1] = '\0';
	ft_resolve_space_filling(details, &result);
	return (result);
}

char	*ft_resolve_spef_str(t_sdetails *details, char *str)
{
	char	*result;

	(void)details;
	result = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	ft_strlcpy(result, str, ft_strlen(str) + 1);
	ft_resolve_space_filling(details, &result);
	return (result);
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

char	*ft_resolve_spef_ptr(t_sdetails *details, unsigned long n)
{
	char	*result;

	(void)details;
	(void)n;
	result = ft_ultostr(n, HEX_CHARS_LOWER);
	details->is_hash = true;
	if (details->is_zero && !details->is_minus)
	{
		ft_fill_left(&result, details->size - 2 - (details->is_plus),
			FILL_ZERO_CHAR);
		ft_appendhash(details, &result);
		ft_resolve_plus(details, &result);
	}
	else
	{
		ft_appendhash(details, &result);
		ft_resolve_plus(details, &result);
		ft_resolve_space_filling(details, &result);
	}
	return (result);
}

char	*ft_resolve_spef_int(t_sdetails *details, int n)
{
	char	*result;

	(void)details;
	result = ft_itoa(n);
	ft_resolve_zero_filling(details, &result);
	ft_resolve_plus(details, &result);
	return (result);
}

char	*ft_resolve_spef_uint(t_sdetails *details, unsigned int n)
{
	char	*result;

	(void)details;
	result = ft_utoa(n);
	ft_resolve_zero_filling(details, &result);
	return (result);
}

// Prints hex in lower case
char	*ft_resolve_spef_lhex(t_sdetails *details, unsigned int n)
{
	char	*result;

	(void)details;
	(void)n;
	result = ft_ultostr(n, HEX_CHARS_LOWER);
	details->is_plus = false;
	if (details->is_zero && !details->is_minus)
	{
		ft_fill_left(&result, details->size - 2 - (details->is_plus),
			FILL_ZERO_CHAR);
		ft_appendhash(details, &result);
	}
	else
	{
		ft_appendhash(details, &result);
		ft_resolve_space_filling(details, &result);
	}
	return (result);
}

// Prints hex in upper case
char	*ft_resolve_spef_uhex(t_sdetails *details, unsigned int n)
{
	char	*result;

	(void)details;
	(void)n;
	result = ft_ultostr(n, HEX_CHARS_UPPER);
	details->is_plus = false;
	if (details->is_zero && !details->is_minus)
	{
		ft_fill_left(&result, details->size - 2 - (details->is_plus),
			FILL_ZERO_CHAR);
		ft_appendhash(details, &result);
	}
	else
	{
		ft_appendhash(details, &result);
		ft_resolve_space_filling(details, &result);
	}
	return (result);
}

char	*ft_resolve_spef_percent(void)
{
	char	*result;

	result = ft_calloc(sizeof(char), 2);
	result[0] = '%';
	result[1] = '\0';
	return (result);
}

// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign
char	*ft_resolve_arg(const char *format, t_sdetails *details, va_list args)
{
	if (details->specifier == 'c')
		return (ft_resolve_spef_char(details, va_arg(args, int)));
	if (details->specifier == 's')
		return (ft_resolve_spef_str(details, va_arg(args, char *)));
	if (details->specifier == 'p')
		return (ft_resolve_spef_ptr(details, va_arg(args, unsigned long)));
	if (ft_stringcludes("di", details->specifier))
		return (ft_resolve_spef_int(details, va_arg(args, int)));
	if (details->specifier == 'u')
		return (ft_resolve_spef_uint(details, va_arg(args, unsigned int)));
	if (details->specifier == 'x')
		return (ft_resolve_spef_lhex(details, va_arg(args, unsigned int)));
	if (details->specifier == 'X')
		return (ft_resolve_spef_uhex(details, va_arg(args, unsigned int)));
	if (details->specifier == '%')
		return (ft_resolve_spef_percent());
	if (details->is_dot_invalid)
		return (ft_resolve_spef_invalid_dot(format, details));
	return (ft_resolve_spef_invalid(format, details));
}
