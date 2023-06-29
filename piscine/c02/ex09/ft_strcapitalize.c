/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:23:12 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/13 14:56:09 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	char	*ptr;
	char	*prev;
	int		cond;

	ptr = str;
	prev = " ";
	while (*str != '\0')
	{
		cond = ((*prev >= 'a' && *prev <= 'z')
				|| (*prev >= 'A' && *prev <= 'Z')
				|| (*prev >= '0' && *prev <= '9'));
		if (!cond && *str >= 'a' && *str <= 'z')
			*str -= 32;
		else if (cond && *str >= 'A' && *str <= 'Z')
			*str += 32;
		prev = str++;
	}
	return (ptr);
}

// int	main()
// {
// 	char	str[] = "HELLO My name is+jeff 42Prague +GSp$";
// 	ft_strcapitalize(str);
// 	printf("%s", str);
// }