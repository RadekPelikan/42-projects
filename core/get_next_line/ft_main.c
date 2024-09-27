/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:49:43 by rpelikan          #+#    #+#             */
/*   Updated: 2024/09/27 13:33:41 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("big_line_with_nl", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	while (line && *line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	close(fd);
}
