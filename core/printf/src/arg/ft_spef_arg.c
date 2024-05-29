/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spef_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:58:11 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 21:30:08 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_helpers.h"

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

void	ft_appendhash(t_sdetails *details, char **result)
{
	char	*hash_str;

	if (!details->is_hash)
		return ;
	hash_str = ft_alloc_str(2);
	ft_strlcpy(hash_str, "0x", 3);
	ft_strappend_start(result, &hash_str);
}

char	*ft_resolve_spef_ptr(t_sdetails *details, unsigned long n)
{
	char	*result;

	(void)details;
	(void)n;
	result = ft_ultostr(n, HEX_CHARS_LOWER);
	// This one will be a little bit tricky
	// with is_zero: '0x0000007fffd5d5e57c'
	// without:      '      0x7ffd7007125c'
	details->is_hash = true;
	if (details->is_zero && !details->is_minus)
	{
		ft_fill_left(&result, details->size - 2, FILL_ZERO_CHAR);
		ft_appendhash(details, &result);
	}
	else
	{
		ft_appendhash(details, &result);
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
	ft_resolve_zero_filling(details, &result);
	return (result);
}

// Prints hex in upper case
char	*ft_resolve_spef_uhex(t_sdetails *details, unsigned int n)
{
	char	*result;

	(void)details;
	(void)n;
	result = ft_ultostr(n, HEX_CHARS_UPPER);
	ft_resolve_zero_filling(details, &result);
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
