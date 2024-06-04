/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:07 by rpelikan          #+#    #+#             */
/*   Updated: 2024/06/01 15:55:27 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char str)
{
	write(1, &str, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_errputstr(char *str)
{
	write(2, str, ft_strlen(str));
}
