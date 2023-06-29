/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:38:04 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/28 20:17:54 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../headers/board.h"
#include "../headers/umatrix.h"
#include "../headers/logic.h"
#include "../headers/out.h"
#include "../headers/utils.h"
#include "../headers/populate.h"

int	find_header(t_board *board, char *pathname)
{
	int		fh;

	fh = open(pathname, O_RDONLY);
	if (fh == -1)
		return (-1);
	else
		populate_header(board, fh);
	if (close(fh) < 0)
		return (-1);
	return (0);
}

int	find_str(t_board *board, char *pathname)
{
	int	fh;

	fh = open(pathname, O_RDONLY);
	(*board).str = (char *) malloc(sizeof(char) * \
	((*board).columns + 1) * (*board).rows);
	if (fh == -1)
		return (-1);
	else
		return (populate_str(board, fh));
	if (close(fh) < 0)
		return (-1);
	return (0);
}

t_board	load_map(char *pathname)
{
	t_board	board;
	int		ret;

	find_header(&board, pathname);
	ret = find_str(&board, pathname);
	if (ret == -1)
		board.columns = 0;
	return (board);
}
