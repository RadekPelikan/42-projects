/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:14 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/29 20:43:32 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_UTILS_H
# define FT_STR_UTILS_H

# include "../libft/libft.h"
# include <stdbool.h>

char	*ft_strappend(char **base, char **tail);
char	*ft_strnjoin(char **strs);
bool	ft_stringcludes(char *str, char c);
char	*ft_strrepeat(const char *str, size_t n);
char	*ft_charrepeat(const char c, size_t n);

#endif
