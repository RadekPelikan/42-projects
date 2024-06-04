/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:33 by rpelikan          #+#    #+#             */
/*   Updated: 2024/06/01 16:23:10 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include "ft_io.h"
# include "ft_printf_helpers.h"
# include "ft_printf_types.h"
# include "ft_str_utils.h"

char	*ft_string_format(const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
