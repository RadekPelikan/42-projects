/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:53:06 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/26 21:55:29 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strfind_first(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		++i;
	return (i);
}

size_t	ft_strfind_last(const char *str, char c)
{
	size_t i;
	size_t len;

	len = ft_strlen(str);
	i = 1;
	while (str[len - i] != c && len - i != 0)
		++i;
	return (len - i);
}