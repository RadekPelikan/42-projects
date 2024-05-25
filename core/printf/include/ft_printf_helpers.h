/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:35 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/25 21:14:31 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPERS_H
# define FT_PRINTF_HELPERS_H


# include <ctype.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "ft_str_utils.h"

#define SPECIFIER_CHARS "cspdiuxX%"

#define FLAG_MINUS '-'
#define FLAG_ZERO '0'
#define FLAG_HASH '#'
#define FLAG_SPACE ' '
#define FLAG_PLUS '+'
#define FLAG_DOT '.'

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
	size_t			index_dot;
	// Edge case
	bool			is_flag_set;
	bool			is_dot_invalid;
	bool			is_invalid;
} t_sdetails;

void	ft_putchar(char str);
void	ft_putstr(char *str);
void	ft_free_str(char *str);
char	*ft_strappend(char **base, char **tail);
char	*ft_strnjoin(char **strs);


#endif
