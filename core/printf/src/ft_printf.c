/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:49:59 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/26 21:10:36 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_helpers.h"

// void	print_sdetails(t_sdetails *details)
// {
// 	printf("== t_sdetails ==\n");
// 	printf("size:           %u\n", details->size);
// 	printf("float_size:     %u\n", details->float_size);
// 	printf("specifier:      %c\n", details->specifier);
// 	printf("is_minus:       %i\n", details->is_minus);
// 	printf("is_zero:        %i\n", details->is_zero);
// 	printf("is_dot:         %i\n", details->is_dot);
// 	printf("is_hash:        %i\n", details->is_hash);
// 	printf("is_space:       %i\n", details->is_space);
// 	printf("is_plus:        %i\n", details->is_plus);
// 	printf("index_size:     %zu\n", details->index_size);
// 	printf("index_dot:      %zu\n", details->index_dot);
// 	printf("index_spef:     %zu\n", details->index_spef);
// 	printf("is_flag_set:    %i\n", details->is_flag_set);
// 	printf("is_dot_invalid: %i\n", details->is_dot_invalid);
// 	printf("is_invalid:     %i\n", details->is_invalid);
// }

// void	print_sresult(t_sresult *seq_result)
// {
// 	printf("== t_sresult ==\n");
// 	printf("result:  %s\n", seq_result->result);
// 	printf("seq_len: %zu\n", seq_result->seq_len);
// }



t_sdetails	*ft_init_sdetails(void)
{
	t_sdetails	*details;

	details = malloc(sizeof(t_sdetails));
	details->index_size = 0;
	details->index_dot = 0;
	details->is_flag_set = false;
	details->is_dot_invalid = false;
	details->is_invalid = false;
	return (details);
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
	t_sdetails	*details;
	t_sresult	*spef_result;

	details = ft_init_sdetails();
	spef_result = malloc(sizeof(t_sresult));
	i = 0;
	while (format[i] != '\0')
	{
		if (ft_check_specifier(format[i], details, i))
			break ;
		++i;
	}
	details->specifier = format[i];
	details->index_spef = i;
	spef_result->seq_len = i + 1;
	ft_extr_sizes(details, format, spef_result->seq_len);
	// print_sdetails(details);
	spef_result->result = ft_resolve_arg(format, details, args);
	free(details);
	return (spef_result);
}

t_sresult	*ft_process_sequence(const char *format, va_list args)
{
	t_sresult	*seq_result;

	if (*format == '%')
	{
		seq_result = ft_resolve_specifier(format + 1, args);
		++seq_result->seq_len;
		// print_sresult(seq_result);
		return (seq_result);
	}
	seq_result = malloc(sizeof(t_sresult));
	seq_result->result = ft_calloc(sizeof(char), 2);
	ft_strlcpy(seq_result->result, format, 2);
	seq_result->seq_len = 1;
	return (seq_result);
}

// Returns a formatted string
char	*ft_string_format(const char *format, ...)
{
	char		*result;
	va_list		args;
	size_t		i;
	t_sresult	*seq_result;

	va_start(args, format);
	i = 0;
	seq_result = ft_process_sequence(format + i, args);
	i = seq_result->seq_len;
	result = seq_result->result;
	free(seq_result);
	seq_result = ft_process_sequence(format + i, args);
	ft_strappend(&result, &seq_result->result);
	i += seq_result->seq_len;
	free(seq_result);
	while (format[i] != '\0')
	{
		seq_result = ft_process_sequence(format + i, args);
		i += seq_result->seq_len;
		ft_strappend(&result, &seq_result->result);
		free(seq_result);
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
	printf("LEN: %zu\n", ft_strlen(result));
	free(result);
	return (ft_strlen(result));
}
