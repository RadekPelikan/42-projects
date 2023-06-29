/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:26:16 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/21 10:07:45 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	includes(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

int	find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (i);
	return (0);
}

int	count_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (!includes("\t\n\v\f\r +-", base[i]) && base[i])
		++i;
	if (base[i] != 0)
		return (0);
	i = 0;
	while (i < ft_strlen(base) - 1)
	{
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			++j;
		}
		++i;
	}
	return (ft_strlen(base));
}

int	ft_atoi_base(char *str, char *base)
{
	int	_base;
	int	i;
	int	j;
	int	nb;
	int	sign;

	_base = count_base(base);
	if (_base == 0)
		return (0);
	nb = 0;
	sign = 1;
	i = 0;
	while (includes("\t\n\v\f\r ", str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		sign *= 1 -2 * (str[i++] == '-' );
	j = i;
	while (str[j] && includes(base, str[j]))
		++j;
	while (includes(base, str[i]))
		nb = nb * _base + find(base, str[i++]) - 1;
	return (nb * sign);
}
/* 
int	main()
{
	char *str;
	char *base;
	int nb;

	str = " -2147483647";
	base = "+0123456789";
	nb = ft_atoi_base(str, base);
	printf("%d\n", nb);
	return (0);
}
 */