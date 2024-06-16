/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:49:59 by rpelikan          #+#    #+#             */
/*   Updated: 2024/06/16 17:07:29 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	printf("index_spef:     %zu\n", details->index_spef);
	printf("is_flag_set:    %i\n", details->is_flag_set);
	printf("is_dot_invalid: %i\n", details->is_dot_invalid);
	printf("is_invalid:     %i\n", details->is_invalid);
}

void	print_sresult(t_sresult *seq_result)
{
	printf("== t_sresult ==\n");
	printf("result:  '%s'\n", seq_result->result);
	printf("seq_len: %zu\n", seq_result->len);
}

t_sdetails	*ft_init_sdetails(void)
{
	t_sdetails	*details;

	details = (t_sdetails *)malloc(sizeof(t_sdetails));
	details->size = 0;
	details->float_size = 0;
	details->specifier = 0;
	details->is_minus = 0;
	details->is_zero = 0;
	details->is_dot = 0;
	details->is_hash = 0;
	details->is_space = 0;
	details->is_plus = 0;
	details->index_size = 0;
	details->index_dot = 0;
	details->index_spef = 0;
	details->is_flag_set = 0;
	details->is_dot_invalid = 0;
	details->is_invalid = 0;
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
t_seqresult	*ft_resolve_specifier(const char *format, va_list args)
{
	size_t		i;
	t_sdetails	*details;
	t_seqresult	*seq_result;

	details = ft_init_sdetails();
	seq_result = malloc(sizeof(t_seqresult));
	i = 0;
	while (format[i] != '\0')
	{
		if (ft_check_specifier(format[i], details, i))
			break ;
		++i;
	}
	details->specifier = format[i];
	details->index_spef = i;
	seq_result->skip = i + 1;
	ft_extr_sizes(details, format, seq_result->skip);
	// print_sdetails(details);
	seq_result->sresult = ft_resolve_arg(format, details, args);
	free(details);
	return (seq_result);
}

t_seqresult	*ft_process_sequence(const char *format, va_list args)
{
	t_seqresult	*seq_result;

	if (*format == '%')
	{
		seq_result = ft_resolve_specifier(format + 1, args);
		++seq_result->skip;
		// print_sresult(seq_result);
		return (seq_result);
	}
	seq_result = malloc(sizeof(t_sresult));
	seq_result->sresult = malloc(sizeof(t_sresult));
	seq_result->sresult->result = ft_calloc(sizeof(char), 2);
	seq_result->sresult->len = 1 * *format != '\0';
	ft_strlcpy(seq_result->sresult->result, format, 2);
	seq_result->skip = 1;
	return (seq_result);
}

// Returns a formatted string
t_fresult	*ft_string_format_fresult(const char *format, ...)
{
	t_fresult	*fresult;
	va_list		args;
	size_t		i;
	t_seqresult	*seq_result;

	fresult = malloc(sizeof(t_fresult));
	va_start(args, format);
	i = 0;
	seq_result = ft_process_sequence(format + i, args);
	fresult->result = seq_result->sresult->result;
	fresult->len = seq_result->sresult->len;
	i = seq_result->skip;
	free_seqresult_keep_str(seq_result);
	if (*format == '\0' || format[i] == '\0')
	{
		va_end(args);
		return (fresult);
	}
	seq_result = ft_process_sequence(format + i, args);
	ft_strappend(&fresult->result, &seq_result->sresult->result);
	fresult->len += seq_result->sresult->len;
	i += seq_result->skip;
	free_seqresult_keep_str(seq_result);
	while (format[i] != '\0')
	{
		seq_result = ft_process_sequence(format + i, args);
		ft_strappend(&fresult->result, &seq_result->sresult->result);
		fresult->len += seq_result->sresult->len;
		i += seq_result->skip;
		free_seqresult_keep_str(seq_result);
	}
	va_end(args);
	return (fresult);
}

char	*ft_string_format(const char *format, ...)
{
	return ft_string_format_fresult(format)->result;
}

// Returns how many charaters has it printed, excluding null byte
// If function encounters an error a negative value is returned
int	ft_printf(const char *format, ...)
{
	t_fresult	*fresult;
	size_t		len;

	fresult = ft_string_format_fresult(format);
	ft_putstr(fresult->result);
	len = fresult->len;
	free_fresult(fresult);
	return (len);
}
