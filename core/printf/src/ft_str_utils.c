/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:05 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/19 18:22:13 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_helpers.h"
#include "../include/ft_str_utils.h"

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
	while (str[i] != c)
		++i;
	if (str[i] == '\0')
		return (true);
	return (false);
}
