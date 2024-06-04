/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:05 by rpelikan          #+#    #+#             */
/*   Updated: 2024/06/01 15:55:20 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_strappend_start(char **base, char **tail)
{
	ft_strappend(tail, base);
	*base = *tail;
	return (*base);
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

char	*ft_strrepeat(const char *str, size_t n)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;
	
	len = ft_strlen(str);
	result = ft_calloc(sizeof(char), len * n + 1);
	i = 0;
	while(i < n * len)
	{
		j = 0;
		while(j < len)
		{
			result[i] = str[j];
			++i;
			++j;
		}
	}
	result[i] = '\0';
	return (result);
}

char	*ft_charrepeat(const char c, size_t n)
{
	char	*result;
	size_t	i;
	
	result = ft_alloc_str(n);
	i = 0;
	while(i < n)
	{
		result[i] = c;
		++i;
	}
	result[i] = '\0';
	return (result);
}
