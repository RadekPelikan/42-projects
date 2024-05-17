/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:59:10 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/21 15:11:38 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	put_str(char *str)
{
	int	len;

	len = 0;
	while (*(str + len++))
		;
	write(1, str, len - 1);
}

int	ft_ten_queens_puzzle(void)
{
	char	queens[] =  "0000000000";
	int		i;
	
	i = 0;
	while (i < sizeof(queens))
	{
		printf("%d\n", i);
		++i;
	}
}

int	main()
{
	ft_ten_queens_puzzle();
}
