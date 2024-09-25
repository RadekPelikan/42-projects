/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_netxt_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:11:58 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/25 23:20:29 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	str_n_cpy(char *src, char *dest, size_t count)
{
	size_t	i;

	if (count == 0)
		return (0);
	i = 0;
	while(src && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	while(i < count)
	{
		dest[i] = '\0';
		++i;
	}
	return (i);
}

char	*str_join(char *str, char *tail)
{
	char	*new_str;
	size_t	old_len;
	size_t	i;

	if (!tail || !*tail)
		return (str);
	old_len = str_len(str);
	new_str = malloc(sizeof(char) * (old_len + str_len(tail) + 1));
	if (!new_str)
		return (NULL);
	i = str_n_cpy(str, new_str, old_len);
	while(tail[i - old_len])
	{
		new_str[i] = tail[i - old_len];
		++i;
	}
	new_str[i] = '\0';
	free(str);
	str = NULL;
	free(tail);
	tail = NULL;
	return (new_str);
}

size_t	str_len(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while(str[len])
		len++;
	return (len);
}
