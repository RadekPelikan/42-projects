/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:59:43 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/15 17:51:50 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

typedef unsigned char	t_byte;

void	print_address_hex(void *);
void	byte_in_hex(t_byte);
void	print_content_hex(void *, unsigned int);
void	print_content_dot(void *, unsigned int);

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size == 1)
		return (addr);
	print_address_hex(addr);
	print_content_hex(addr, size);
	print_content_dot(addr, size);
	return (addr);
}

void	byte_in_hex(t_byte Byte)
{
	int		_4_upper_bits;
	int		_4_lower_bits;
	char	c;

	_4_upper_bits = (Byte & 0b11110000) >> 4;
	if (_4_upper_bits > 9)
		c = _4_upper_bits + 87;
	else
		c = _4_upper_bits + 48;
	write(1, &c, 1);
	_4_lower_bits = Byte & 0b00001111;
	if (_4_lower_bits > 9)
		c = _4_lower_bits + 87;
	else
		c = _4_lower_bits + 48;
	write(1, &c, 1);
}

void	print_address_hex(void *addr)
{
	t_byte	*ptr_byte;
	int		little_endian;

	little_endian = 7;
	ptr_byte = (t_byte *) &addr;
	while (little_endian >= 0)
	{
		byte_in_hex(*(ptr_byte + little_endian));
		--little_endian;
	}
	write(1, ":", 1);
}

void	print_content_hex(void *str, unsigned int size)
{
	int		i;
	short	limit;

	limit = 16;
	i = 0;
	while (--size && limit--)
	{
		if (!(i % 2))
			write(1, " ", 1);
		byte_in_hex(*((t_byte *)str));
		++str;
		++i;
	}
	if (i % 2)
		write(1, "  ", 2);
	else
		write(1, " ", 1);
}

void	print_content_dot(void *str, unsigned int size)
{
	short	limit;

	limit = 16;
	while (--size && limit--)
	{
		if (*(char *)str >= ' ' && *(char *)str < '~')
			write(1, str, 1);
		else
			write(1, ".", 1);
		++str;
	}	
	write(1, "\n", 1);
}

// int 	main()
// {
// 	char	empty[] = "";
	

// 	char	str[] = "Bonjour les amin----";
// 	char	str1[] = "ches\t\n\tc  est fo----";
// 	char	str2[] = "u\ttout\tce qu on ----";
// 	char	str3[] = "peut faire avec\t----";
// 	char	str4[] = "\n\tprint_memory\n\n----";
// 	char 	str5[] = "\n\tlol.lol\n \0";

// 	ft_print_memory((void *)empty, sizeof(empty));
// 	ft_print_memory((void *)str, sizeof(str));
// 	ft_print_memory((void *)str1, sizeof(str1));
// 	ft_print_memory((void *)str2, sizeof(str2));
// 	ft_print_memory((void *)str3, sizeof(str3));
// 	ft_print_memory((void *)str4, sizeof(str4));
// 	ft_print_memory((void *)str5, sizeof(str5));
// }
