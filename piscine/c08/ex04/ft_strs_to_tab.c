/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:54:47 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/29 16:33:11 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include "stdlib.h"
#include "stdio.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = 0;
	return (dest);
}

// typedef struct s_stock_str
// {
// 	int		size;
// 	char	*str;
// 	char	*copy;
// }	t_stock_str;

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
// void	ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			i;

	res = malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		res[i].size = ft_strlen(av[i]);
		++i;
	}
	res[i].size = 0;
	return (res);
}

//////////////////////////////////////////////////
// Another exercise
//////////////////////////////////////////////////

// #include <unistd.h>

// void	ft_putstr(char *str)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	while (str[len])
// 		len++;
// 	write(1, str, len);
// }

// void	ft_putnbr(int nb)
// {
// 	char	c;

// 	if (nb == -2147483648)
// 	{
// 		write(1, "-", 1);
// 		write(1, "2", 1);
// 		nb = 147483648;
// 	}
// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb = nb * (-1);
// 	}
// 	if (nb / 10 > 0)
// 		ft_putnbr(nb / 10);
// 	c = nb % 10 + '0';
// 	write(1, &c, 1);
// }

// void	ft_show_tab(struct s_stock_str *par)
// {
// 	int	i;

// 	i = 0;
// 	while (par[i].size != 0)
// 	{
// 		ft_putstr(par[i].str);
// 		ft_putstr("\n");
// 		ft_putnbr(par[i].size);
// 		ft_putstr("\n");
// 		ft_putstr(par[i].copy);
// 		ft_putstr("\n");
// 		++i;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	t_stock_str *par = ft_strs_to_tab(argc, argv);
// 	ft_show_tab(par);
// }
