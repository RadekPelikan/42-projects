/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:05 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/25 21:00:47 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_helpers.h"
#include "../include/ft_str_utils.h"

char	*ft_strappend(char **base, char **tail)
{
	char	*result;

	if (!*tail)
		return (NULL);
	if (!*base)
		*base = malloc(0);
	result = ft_strjoin(*base, *tail);
	if (!result)
		return (NULL);
	free(*base);
	free(*tail);
	*base = result;
	return (result);
}

char	*ft_strnjoin(char **strs)
{
	size_t	i;
	size_t	len;
	char	*result;
	char	*temp;

	i = 0;
	len = 0;
	while (strs[len])
		++len;
	result = ft_strjoin(strs[0], strs[1]);
	i = 2;
	while (i < len)
	{
		temp = ft_strjoin(result, strs[i]);
		free(result);
		result = temp;
		++i;
	}
	return (result);
}

bool	ft_stringcludes(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		++i;
	return (str[i] != '\0');
}

size_t	ft_find_last(const char *str, char c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 1;
	while (str[len - i] != c && len - i != 0)
		++i;
	return (len - i);
}
