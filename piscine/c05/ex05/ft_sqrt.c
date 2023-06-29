/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:37:43 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/23 11:12:42 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	result;

	if (nb == 1)
		return (1);
	else if (nb <= 3)
		return (0);
	i = 1;
	result = 1;
	while (result <= nb && result > 0)
	{
		++i;
		result = i * i;
	}	
	--i;
	if (i * i != nb)
		return (0);
	return (i);
}
/*
int	main()
{
	// int base;

	printf("%d\n", ft_sqrt(256));
	// for (int i = 0; i < 10000; ++i)
	// {
	// 	base = ft_sqrt(i);
	// 	if (base)
	// 		printf("\n%d: %d", i, base);
	// 	// else
	// 	// 	printf("%d, ", i);
	// }
}
*/
