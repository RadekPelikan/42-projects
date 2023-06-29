/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:21:47 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/20 16:27:56 by rpelikan         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	len;
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		len = ft_strlen(*(argv + i));
		write(1, *(argv + i), len);
		write(1, "\n", 1);
		--i;
	}
	return (0);
}
