/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:02:30 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/16 16:15:42 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb)
	{
		res *= nb--;
	}
	return (res);
}

// int	main()
// {
// 	for (int i = 0; i < 10; ++i)
// 		printf("%i: %i\n", i, ft_iterative_factorial(i));
// }