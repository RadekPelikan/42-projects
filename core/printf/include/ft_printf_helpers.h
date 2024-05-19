/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:35 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/19 17:56:50 by rpelikan         ###   ########.fr       */
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

// typedef struct s_list
// {
//     void *content;
//     struct s_list *next;
// } t_list;

void	ft_putstr(const char *str);
void	ft_free_str(char *str);
char	*ft_strnjoin(char **strs);

#endif
