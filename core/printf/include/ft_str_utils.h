/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:14 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/23 21:15:52 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_UTILS_H
# define FT_STR_UTILS_H

# include "../libft/libft.h"
# include <stdbool.h>

#define SPECIFIER_CHARS "cspdiuxX"

char	*ft_strnjoin(char **strs);
bool	ft_stringcludes(char *str, char c);
size_t	ft_find_last(const char *str, char c);

#endif
