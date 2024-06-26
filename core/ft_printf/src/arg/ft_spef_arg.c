/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spef_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:58:11 by rpelikan          #+#    #+#             */
/*   Updated: 2024/06/16 16:18:35 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sresult	*ft_resolve_spef_char(t_sdetails *details, char c)
{
	t_sresult	*spef_result;
	char		*result;

	spef_result = malloc(sizeof(t_sresult));
	if (spef_result == NULL)
		return (NULL);
	result = ft_calloc(sizeof(char), 2);
	spef_result->result = result;
	result[0] = c;
	result[1] = '\0';
	ft_resolve_space_filling(details, &result);
	spef_result->len = ft_strlen(result) + (c == 0);
	return (spef_result);
}

t_sresult	*ft_resolve_spef_str(t_sdetails *details, char *str)
{
	t_sresult	*spef_result;
	char		*result;

	spef_result = malloc(sizeof(t_sresult));
	if (spef_result == NULL)
		return (NULL);
	result = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	spef_result->result = result;
	ft_strlcpy(result, str, ft_strlen(str) + 1);
	ft_resolve_space_filling(details, &result);
	spef_result->len = ft_strlen(result);
	return (spef_result);
}

t_sresult	*ft_resolve_spef_ptr(t_sdetails *details, unsigned long n)
{
	t_sresult	*spef_result;
	char		*result;

	spef_result = malloc(sizeof(t_sresult));
	if (spef_result == NULL)
		return (NULL);
	result = ft_ultostr(n, HEX_CHARS_LOWER);
	spef_result->result = result;
	details->is_hash = true;
	if (details->is_zero && !details->is_minus)
	{
		ft_reolve_zero_hash_filling(details, &result);
		ft_resolve_plus(details, &result);
	}
	else
	{
		ft_appendhash(details, &result);
		ft_resolve_plus(details, &result);
		ft_resolve_space_filling(details, &result);
	}
	spef_result->len = ft_strlen(result);
	return (spef_result);
}

t_sresult	*ft_resolve_spef_int(t_sdetails *details, int n)
{
	t_sresult	*spef_result;
	char		*result;

	spef_result = malloc(sizeof(t_sresult));
	if (spef_result == NULL)
		return (NULL);
	result = ft_itoa(n);
	spef_result->result = result;
	ft_resolve_zero_filling(details, &result);
	ft_resolve_plus(details, &result);
	spef_result->len = ft_strlen(result);
	return (spef_result);
}

t_sresult	*ft_resolve_spef_uint(t_sdetails *details, unsigned int n)
{
	t_sresult	*spef_result;
	char		*result;

	spef_result = malloc(sizeof(t_sresult));
	if (spef_result == NULL)
		return (NULL);
	result = ft_utoa(n);
	spef_result->result = result;
	ft_resolve_zero_filling(details, &result);
	spef_result->len = ft_strlen(result);
	return (spef_result);
}

// Prints hex in lower case
t_sresult	*ft_resolve_spef_lhex(t_sdetails *details, unsigned int n)
{
	t_sresult	*spef_result;
	char		*result;

	spef_result = malloc(sizeof(t_sresult));
	if (spef_result == NULL)
		return (NULL);
	result = ft_ultostr(n, HEX_CHARS_LOWER);
	spef_result->result = result;
	details->is_plus = false;
	if (details->is_zero && !details->is_minus)
		ft_reolve_zero_hash_filling(details, &result);
	else
	{
		ft_appendhash(details, &result);
		ft_resolve_space_filling(details, &result);
	}
	spef_result->len = ft_strlen(result);
	return (spef_result);
}

// Prints hex in upper case
t_sresult	*ft_resolve_spef_uhex(t_sdetails *details, unsigned int n)
{
	t_sresult	*spef_result;
	char		*result;

	spef_result = malloc(sizeof(t_sresult));
	if (spef_result == NULL)
		return (NULL);
	result = ft_ultostr(n, HEX_CHARS_UPPER);
	spef_result->result = result;
	details->is_plus = false;
	if (details->is_zero && !details->is_minus)
	{
		ft_fill_left(&result, (details->size - 2 - (details->is_plus))
			* (details->size != 0), FILL_ZERO_CHAR);
		ft_appendhash(details, &result);
	}
	else
	{
		ft_appendhash(details, &result);
		ft_resolve_space_filling(details, &result);
	}
	spef_result->len = ft_strlen(result);
	return (spef_result);
}

t_sresult	*ft_resolve_spef_percent(void)
{
	t_sresult	*spef_result;
	char		*result;

	spef_result = malloc(sizeof(t_sresult));
	if (spef_result == NULL)
		return (NULL);
	result = ft_calloc(sizeof(char), 2);
	spef_result->result = result;
	result[0] = '%';
	result[1] = '\0';
	spef_result->len = ft_strlen(result);
	return (spef_result);
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
t_sresult	*ft_resolve_arg(const char *format, t_sdetails *details,
		va_list args)
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
