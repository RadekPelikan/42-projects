/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:01:34 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/29 13:00:24 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*num_arr;
	int	len;
	int	i;

	num_arr = malloc(sizeof(int));
	len = max - min;
	if (len <= 0)
	{
		*num_arr = 0;	
		return (num_arr);
	}
	num_arr = malloc(sizeof(int) * len + 1);
	i = 0;
	while (i < len)
	{
		*(num_arr + i) = i + min;
		++i;
	}
	num_arr[i] = 0;
	return (num_arr);
}

/* 
int	main()
{
	int	min = 0;
	int max = 10;
	int	*num_arr = ft_range(min, max);
	for (int i = 0; i < max - min; ++i)
		printf("%d ", *(num_arr + i));
	free(num_arr);
}
 */
