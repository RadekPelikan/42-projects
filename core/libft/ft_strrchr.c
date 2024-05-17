/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:13:38 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/09 10:32:28 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp[9999];
	int	i;

	i = 0;
	while (i < size)
	{
		temp[i] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[size - i - 1] = temp[i];
		i++;
	}
}

// int	main(void)
// {
// 	int	length = 10;
// 	int	nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// 	ft_rev_int_tab(&nums[0], length);

// 	for(int i = 0; i < length; i++)
//       		printf("%d ", nums[i]);
// }