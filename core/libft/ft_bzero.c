/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:50:10 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/16 17:58:29 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	return (1);
}

// int	main()
// {
// 	for (int i = 0; i < 100; ++i)
// 		printf("%2d: %s\n", i, ft_is_prime(i) ? "PRIME" : "NOT PRIME");
// }