/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:17:03 by rpelikan          #+#    #+#             */
/*   Updated: 2024/01/14 15:50:56 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

// int main()
// {
// 	char yes = 'C';
// 	char no = '4';

// 	printf("%c: %s\n", yes, ft_isalpha(yes) == isalpha(yes)
//  	? "passed" : "failed");
// 	printf("%c: %s\n", no, ft_isalpha(no) == isalpha(no)
//  	? "passed" : "failed");
// }