/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:54:11 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/08 23:10:44 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	num_a;
	int	num_b;

	num_a = *a;
	num_b = *b;
	*a = num_a / num_b;
	*b = num_a % num_b;
}

// int	main(void)
// {
// 	int	num_a;
// 	int	num_b;

// 	num_a = 13;
// 	num_b = 2;
// 	ft_ultimate_div_mod(&num_a, &num_b);
// 	printf("Division: %d | Remainder: %d", num_a, num_b);
// }
