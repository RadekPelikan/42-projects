/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:08:39 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/29 13:00:31 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	len = max - min;
	if (len <= 0)
		return (0);
	*range = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		(*range)[i] = i + min;
		++i;
	}
	(*range)[i] = 0;
	return (len);
}

// int	main()
// {
// 	int *range;

// 	int len = ft_ultimate_range(&range, 1, 10);
// 	for (int i = 0; i < len; ++i)
// 		printf("%d ", range[i]);
// }
