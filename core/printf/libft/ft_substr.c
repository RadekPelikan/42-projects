/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:58:37 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 19:03:32 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(size_t len, unsigned int start, char *ptr, char const *s)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		ptr[count] = s[start + count];
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count;
	char			*ptr;

	if (!s || start < 0)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[0] = 0;
		return (ptr);
	}
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	count = ft_count(len, start, ptr, s);
	ptr[count] = '\0';
	return (ptr);
}

// int main(void) {
// 	char str1[40] = "Hello world!";
// 	size_t start = 6;

// 	puts(str1);
// 	char *str2 = ft_substr(str1, start, 2);
// 	puts(str2);
// }
