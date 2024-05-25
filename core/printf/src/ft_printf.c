/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:49:59 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/26 00:13:47 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_helpers.h"

void	print_sdetails(t_sdetails *details)
{
	printf("== t_sdetails ==\n");
	printf("size:           %u\n", details->size);
	printf("float_size:     %u\n", details->float_size);
	printf("specifier:      %c\n", details->specifier);
	printf("is_minus:       %i\n", details->is_minus);
	printf("is_zero:        %i\n", details->is_zero);
	printf("is_dot:         %i\n", details->is_dot);
	printf("is_hash:        %i\n", details->is_hash);
	printf("is_space:       %i\n", details->is_space);
	printf("is_plus:        %i\n", details->is_plus);
	printf("index_size:     %zu\n", details->index_size);
	printf("index_dot:      %zu\n", details->index_dot);
	printf("is_flag_set:    %i\n", details->is_flag_set);
	printf("is_dot_invalid: %i\n", details->is_dot_invalid);
	printf("is_invalid:     %i\n", details->is_invalid);
}

void	print_sresult(t_sresult *spef_result)
{
	printf("== t_sresult ==\n");
	printf("result:        %s\n", spef_result->result);
	printf("specifier_len: %zu\n", spef_result->specifier_len);
}

bool	ft_is_start_flag(char c)
{
	return (c == FLAG_MINUS || c == FLAG_HASH || c == FLAG_SPACE
		|| c == FLAG_PLUS);
}

// Returns the number of characters than were extracted from the format
size_t	ft_extract_num(unsigned int *size, const char *format, size_t len)
{
	char	*extracted_num;

	printf("LEN: %zu | format: %s\n", len, format);
	extracted_num = ft_calloc(sizeof(char), len + 1);
	ft_strlcpy(extracted_num, format, len + 1);
	*size = (unsigned int)ft_atoi(extracted_num);
	printf("EXTRACTED: %s | digit: %u\n", extracted_num, *size);
	free(extracted_num);
	return (len);
}

void	ft_extract_sizes(t_sdetails *details, const char *format, size_t spef_len)
{
	size_t	index_end;

	index_end = details->index_dot;
	if (details->is_dot)
		index_end = details->index_dot;
	else
		index_end = spef_len;
	ft_extract_num(&(details->size), format + details->index_size,
		index_end - details->index_size);
	ft_extract_num(&(details->float_size), format + index_end + 1,
		spef_len - index_end);
	// ft_extract_num(&(details->size), format + details->index_size,
	// 	details->index_dot - details->index_size);
	// ft_extract_num(&(details->float_size), format + details->index_dot + 1,
	// 	spef_len - details->index_dot);
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

bool	ft_check_dot_specifier(const char spef_c, t_sdetails *details, size_t i)
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
	if (is_specifier_char)
		return (true);
	if (!details->is_flag_set && (ft_is_start_flag(spef_c)
			|| ((details->index_size != 0 || !details->is_dot) && spef_c == FLAG_ZERO)))
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
	if (ft_check_dot_specifier(spef_c, details, i))
		return (true);
	return (false);
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
t_sresult	*ft_resolve_specifier(const char *format, va_list args)
{
	size_t		i;
	char		*arg;
	t_sdetails	*details;
	t_sresult	*spef_result;

	details = malloc(sizeof(t_sdetails));
	spef_result = malloc(sizeof(t_sresult));
	details->is_dot_invalid = false;
	details->is_invalid = false;
	i = 0;
	while (format[i] != '\0')
	{
		if (ft_check_specifier(format[i], details, i))
			break ;
		++i;
	}
	details->specifier = format[i];
	spef_result->specifier_len = i + 1;
	ft_extract_sizes(details, format, spef_result->specifier_len);
	print_sdetails(details);
	free(details);
	arg = va_arg(args, char *);
	spef_result->result = ft_calloc(sizeof(char), ft_strlen(arg) + 1);
	ft_strlcpy(spef_result->result, arg, ft_strlen(arg) + 1);
	return (spef_result);
}

// Returns a formatted string
char	*ft_string_format(const char *format, ...)
{
	char		*result;
	va_list		args;
	size_t		i;
	char		*char_sequence;
	t_sresult	*spef_result;

	i = 0;
	va_start(args, format);
	result = NULL;
	while (format[i] != '\0')
	{
		// TODO: Final result is printed badly, sometimes with more characters at the front
		// Bug is in strappend, need to initialize the result first
		if (format[i] == '%')
		{
			spef_result = ft_resolve_specifier(format + i + 1, args);
			i += spef_result->specifier_len + 1;
			char_sequence = spef_result->result;
			print_sresult(spef_result);
		}
		else
		{
			char_sequence = ft_calloc(sizeof(char), 2);
			ft_strlcpy(char_sequence, format + i, 2);
			++i;
		}
		ft_strappend(&result, &char_sequence);
	}
	va_end(args);
	return (result);
}

// Returns how many charaters has it printed, excluding null byte
// If function encounters an error a negative value is returned
int	ft_printf(const char *format, ...)
{
	char	*result;

	result = ft_string_format(format);
	ft_putstr(result);
	// printf("LEN: %zu\n", ft_strlen(result));
	free(result);
	return (0);
}
