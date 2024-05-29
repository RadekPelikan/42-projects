/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:35 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 20:46:14 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPERS_H
# define FT_PRINTF_HELPERS_H

# include "../libft/libft.h"
# include "ft_io.h"
# include "ft_printf_types.h"
# include "ft_str_utils.h"
// # include <ctype.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SPECIFIER_CHARS "cspdiuxX%"

# define FLAG_MINUS '-'
# define FLAG_ZERO '0'
# define FLAG_HASH '#'
# define FLAG_SPACE ' '
# define FLAG_PLUS '+'
# define FLAG_DOT '.'

# define HEX_CHARS_LOWER "0123456789abcdef"
# define HEX_CHARS_UPPER "0123456789ABCDEF"


// arg
char	*ft_resolve_arg(const char *format, t_sdetails *details, va_list args);

void	ft_fill_left(char **src, size_t len, char c);
void	ft_fill_right(char **src, size_t len, char c);


char	*ft_ultohex(unsigned long n);
char	*ft_ultostr(unsigned long n, const char *chars);


// spef (specifier)

bool	ft_is_start_flag(char c);
void	ft_enable_start_flag(t_sdetails *details, char c);
bool	ft_check_start_flag(const char spef_c, t_sdetails *details, size_t i);
bool	ft_check_dot_spef(const char spef_c, t_sdetails *details, size_t i);
// Validates the specifier
// If it encounters an invalid character or sequence of characters then it returns
// Sets invalid attributes in t_sdetails
// Returns (bool) if specifier is finished
bool	ft_check_specifier(const char spef_c, t_sdetails *details, size_t i);

// Returns the number of characters than were extracted from the format
size_t	ft_extr_num(unsigned int *size, const char *format, size_t len);
// Extracts size and float_size from specifier (format) to details
void	ft_extr_sizes(t_sdetails *details, const char *format, size_t spef_len);




#endif
