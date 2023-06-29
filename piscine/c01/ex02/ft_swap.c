/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:27:02 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/08 20:45:47 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int	main(void)
// {
// 	int	*ptr_a;
// 	int	*ptr_b;
// 	int	num_a;
// 	int	num_b;

// 	num_a = 69;
// 	num_b = 420;
// 	ptr_a = &num_a;
// 	ptr_b = &num_b;
// 	printf("A: %3d | B: %3d\n", num_a, num_b);
// 	ft_swap(ptr_a, ptr_b);
// 	printf("A: %3d | B: %3d", num_a, num_b);
// }