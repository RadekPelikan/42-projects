/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 01:57:50 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/19 20:50:34 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft.h"

# define DEC_CHARS "0123456789"
# define HEX_CHARS_LOWER "0123456789abcdef"
# define HEX_CHARS_UPPER "0123456789ABCDEF"

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(uintptr_t ptr);
int	ft_putdecnum(int num);
int	ft_putunsignednum(unsigned int num);
int	ft_putlowerhex(unsigned int num);
int	ft_putupperhex(unsigned int num);

int	ft_putnum(long n, char *chars);
int	ft_put_unum(unsigned long n, char *chars);

#endif
