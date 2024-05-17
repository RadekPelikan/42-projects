/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:46:34 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/09 10:32:52 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int	main(void)
// {
// 	int	num_a;
// 	int	num_b;
// 	int	div;
// 	int	mod;

// 	num_a = 13;
// 	num_b = 2;
// 	ft_div_mod(num_a, num_b, &div, &mod);
// 	printf("%d / %d = %d | reminder = %d", num_a, num_b, div, mod);
// }
