/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:07 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/25 20:24:37 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_helpers.h"

void ft_putchar(char str) {
	write(1, &str, 1);
}

void ft_putstr(char *str) {
	write(1, str, ft_strlen(str));
}
