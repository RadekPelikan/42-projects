/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:18:36 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 18:04:45 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	ptr = malloc(sizeof(char) * (end - start) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (end > start)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

// int main(void) {
// 	char str[40] = "  . ..--..//Hello World! ..\t   -..";
// 	char set[40] = " .-/\t";

// 	puts(str);
// 	char *str2 = ft_strtrim(str, set);
// 	puts(str2);
// }
