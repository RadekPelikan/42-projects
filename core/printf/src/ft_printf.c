/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:49:59 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/19 18:10:22 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_helpers.h"

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
	size_t	i;
	char	*result;

	if (format[1] == '%')
	{
		result = malloc(2 * sizeof(char));
		result[0] = '%';
		result[1] = '\0';
		return (result);
	}
	i = 0;
	while (format[i] != '\0')
	{
		if (ft_stringcludes(SPECIFIER_CHARS, format[i]))
			break ;
		++i;
	}
	(void) args;
	printf("END: %zu\n", i);
	result = NULL;
	return (result);
}

// Returns a formatted string
char	*ft_string_format(const char *format, ...)
{
	char	*result;
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, format);
	result = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_resolve_specifier(format + i, args);
		}
		else
		{
		}
		++i;
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
	return (0);
}
