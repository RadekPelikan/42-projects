/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:39:15 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/16 12:01:41 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		str_c;
	int		fin_c;
	int		l;

	str_c = 0;
	if (!to_find)
		return (str);
	while (*(str + str_c))
	{
		fin_c = str_c;
		l = 0;
		while (*(str + fin_c) == *(to_find + l) && *(to_find + l))
		{
			++fin_c;
			++l;
		}
		if (!(*(to_find + l)))
			return (str + str_c);
		++str_c;
	}
	return (NULL);
}

// int	main()
// {
// 	char str0[] = "";
// 	char str1[] = "";
// 	char to_find0[] = "Hello World";
// 	char to_find1[] = "Hello World";
// 	printf("%s\n", ft_strstr(str0, to_find0));
// 	printf("%s\n", strstr(str1, to_find1));
// 	return (0);
// }