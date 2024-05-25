/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:49:59 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/25 21:20:51 by rpelikan         ###   ########.fr       */
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
	printf("is_flag_set:    %i\n", details->is_flag_set);
	printf("is_dot_invalid: %i\n", details->is_dot_invalid);
	printf("is_invalid:     %i\n", details->is_invalid);
}

bool	ft_is_start_flag(char c)
{
	return (c == FLAG_MINUS || c == FLAG_HASH
		|| c == FLAG_SPACE || c == FLAG_PLUS);
}

void	ft_enable_start_flag(t_sdetails *details, char c) {
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

// Validates the specifier
// If it encounters an invalid character or sequence of characters then it returns
// Sets invalid attributes in t_sdetails
// Returns (bool) if specifier is finished
bool	ft_check_specifier(const char *format, t_sdetails *details, size_t i)
{
	bool	is_specifier_char;
	bool	is_number;

	is_specifier_char = ft_stringcludes(SPECIFIER_CHARS, format[i]);
	is_number = ft_isdigit(format[i]);
	if (is_specifier_char)
		return (true);
	if (ft_is_start_flag(format[i]))
		ft_enable_start_flag(details, format[i]);

	if (!details->is_flag_set && is_number)
		details->is_flag_set = true;
	else if (details->is_flag_set && ft_is_start_flag(format[i]))
	{
		details->is_invalid = true;
		return (true);
	}
	if (format[i] == FLAG_DOT && !details->is_dot)
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

// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign
char	*ft_resolve_specifier(const char *format, va_list args)
{
	size_t		i;
	char		*result;
	char		*arg;
	t_sdetails	*details;

	details = malloc(sizeof(t_sdetails));
	details->is_dot_invalid = false;
	details->is_invalid = false;
	i = 1;
	while (format[i] != '\0')
	{
		if (ft_check_specifier(format, details, i))
			break ;
		// if (is_number && !details->is_dot)
		// 	ft_extract_num(&(details->size), format[i], details->index_dot);

		++i;
	}
	details->specifier = format[i];
	print_sdetails(details);
	(void)args;
	result = NULL;
	free(details);

	arg = va_arg(args, char*);
	result = ft_calloc(sizeof(char), ft_strlen(arg) + 1);
	ft_strlcpy(result, arg, ft_strlen(arg) + 1);
	return (result);
}

// Returns a formatted string
char	*ft_string_format(const char *format, ...)
{
	char	*result;
	va_list	args;
	size_t	i;
	char	*char_sequence;

	i = 0;
	va_start(args, format);
	result = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			char_sequence = ft_resolve_specifier(format + i, args);
			i += ft_strlen(char_sequence) + 1;
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
