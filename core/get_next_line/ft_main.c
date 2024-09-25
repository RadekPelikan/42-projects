/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:49:43 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/25 23:24:14 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("00.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line && *line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}
