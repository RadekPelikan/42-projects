/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:28:14 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/21 12:51:15 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s1[i] || s2[i])
	{
		result = s1[i] - s2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (result);
}

void	str_swap(char **str_arr, int i, int j)
{
	char	*temp;

	temp = str_arr[i];
	str_arr[i] = str_arr[j];
	str_arr[j] = temp;
}

void	sort(char **str_arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(str_arr[i], str_arr[j]) > 0)
				str_swap(str_arr, i, j);
			++j;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int		len;
	int		i;

	sort(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(*(argv + i));
		write(1, *(argv + i), len);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
