/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:09:55 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/16 16:20:23 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power)
	{
		res *= nb;
		--power;
	}
	return (res);
}

// int	main()
// {
// 	for (int i = 0; i < 10; ++i)
// 		for (int j = 0; j < 10; ++j)
// 			printf("%i ** %i = %i\n", i, j, ft_iterative_power(i, j));
// }