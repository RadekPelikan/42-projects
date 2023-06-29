/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:06:51 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/15 19:08:16 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (!(
				(*str >= 'a' && *str <= 'z')
				|| (*str >= 'A' && *str <= 'Z')))
			return (0);
		++str;
	}
	return (1);
}

// int	main()
// {
// 	char	str[] = "ab4dggdfgdfg"; {
// 	char	str1[] = "test1";
// 	char	str2[] = "test2";

// 	ft_strcpy(str2, str1);
// 	printf("%s", str2);
// }
// 	if (ft_str_is_aplha(str))
// 		printf("Only alpha");
// 	else
// 		printf("Something else");
// }