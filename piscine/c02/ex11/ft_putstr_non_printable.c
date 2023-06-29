/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:34:52 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/15 17:27:18 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	write_hex(char byte)
{
	char	c;

	write(1, "\\", 2);
	if (byte / 16 > 9)
		c = byte / 16 + 87;
	else
		c = byte / 16 + 48;
	write(1, &c, 1);
	if (byte % 16 > 9)
		c = byte % 16 + 87;
	else
		c = byte % 16 + 48;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || *str > '~')
			write_hex(*str);
		else
			write(1, str, 1);
		++str;
	}
}

// int	main(void)
// {
// 	char	*str = "Coucou\ntu vas bien ?\f";
// 	ft_putstr_non_printable(str);
// 	return 0;
// }