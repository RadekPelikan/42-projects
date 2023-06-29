/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:20:00 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/16 16:22:54 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (!power)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

// int	main()
// {
// 	for (int i = 0; i < 10; ++i)
// 		for (int j = 0; j < 10; ++j)
// 			printf("%i ** %i = %i\n", i, j, ft_recursive_power(i, j));
// }