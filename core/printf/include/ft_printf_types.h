/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:06:25 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/26 21:11:01 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# include <unistd.h>
# include <stdbool.h>

// (specifier) char
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign
typedef struct s_specifier_details
{
	unsigned int	size;
	unsigned int	float_size;
	char			specifier;
	// Bonus Flags
	bool			is_minus;
	bool			is_zero;
	bool			is_dot;
	bool			is_hash;
	bool			is_space;
	bool			is_plus;
	// Help attributes
	size_t			index_size;
	size_t			index_dot;
	size_t			index_spef;
	// Edge case
	bool			is_flag_set;
	bool			is_dot_invalid;
	bool			is_invalid;
}					t_sdetails;

typedef struct s_sequence_result
{
	char			*result;
	size_t			seq_len;
}					t_sresult;

#endif