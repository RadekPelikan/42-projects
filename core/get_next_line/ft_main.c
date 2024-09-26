/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:49:43 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/26 00:36:52 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("01.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line && *line)
	{
		printf("%s", line);
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
}
