/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:14:05 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 18:11:11 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	base;
	int	sign;

	i = 0;
	base = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		base = base * 10 + (s[i] - '0');
		i++;
	}
	return (base * sign);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("   300"));
// 	printf("%d\n\n", atoi("   300"));
// 	printf("%d\n", ft_atoi("310"));
// 	printf("%d\n\n", atoi("310"));
// 	printf("%d\n", ft_atoi("-320"));
// 	printf("%d\n\n", atoi("-320"));
// 	printf("%d\n", ft_atoi("+330"));
// 	printf("%d\n\n", atoi("+330"));
// 	printf("%d\n", ft_atoi("g340"));
// 	printf("%d\n\n", atoi("g340"));
// 	printf("%d\n", ft_atoi("+-350"));
// 	printf("%d\n\n", atoi("+-350"));
// 	printf("%d\n", ft_atoi("dfgdfg 400"));
// 	printf("%d\n\n", atoi("dfgdfg 400"));
// 	printf("%d\n", ft_atoi("--410"));
// 	printf("%d\n\n", atoi("--410"));
// 	printf("%d\n", ft_atoi("-3-420"));
// 	printf("%d\n\n", atoi("-3-420"));
// 	printf("%d\n", ft_atoi("45 - 34"));
// 	printf("%d\n\n", atoi("45 - 34"));
// 	printf("%d\n", ft_atoi("23.000003"));
// 	printf("%d\n\n", atoi("23.000003"));
// }
