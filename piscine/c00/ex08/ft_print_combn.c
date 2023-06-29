/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:16:48 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/08 18:10:09 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_nbr(int total, int *prev_ptr[])
{
	int	comma;
	int	i;

	comma = 0;
	i = 0;
	while (i < total)
	{
		ft_putchar(*prev_ptr[i] + 48);
		if (10 - total + i != *prev_ptr[i])
			comma = 1;
		i++;
	}
	if (comma)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

// int count = 0;

void	ft_comb_level(int total, int level, int *prev_ptr[])
{
	int	i;

	i = 0;
	if (level > 0)
		i = *prev_ptr[level - 1] + 1;
	while (i < 10)
	{
		prev_ptr[level] = &i;
		if (level < total)
			ft_comb_level(total, level + 1, prev_ptr);
		if (level == total - 1)
		{
			ft_print_nbr(total, prev_ptr);
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	*prev_ptr[10];
	int	zero;

	zero = 0;
	prev_ptr[0] = &zero;
	ft_comb_level(n, 0, prev_ptr);
}

// int	main()
// {
// 	ft_print_combn(5);
// 	return 0;
// 	// int i = 1;
// 	// while (i < 10)
// 	// {
// 	// 	count = 0;
// 	// 	ft_print_combn(i);
// 	// 	printf("%d: %d\n",i, count);
// 	// 	i++;
// 	// }
// }