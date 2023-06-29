/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:27:56 by rpelikan          #+#    #+#             */
/*   Updated: 2023/06/28 20:30:09 by rpelikan         ###   ########.fr       */
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

int	fill_attributes(t_board *board, char *str)
{
	int	i;
	int	j;

	(*board).rows = smpl_atoi(&str);
	i = 0;
	while (i < 3)
	{
		if (str[i] <= ' ' || str[i] >= '~')
			return (-1);
		j = i + 1;
		while (i + j < 4)
		{
			if (str[i] == str[j])
				return (-1);
			++j;
		}
		++i;
	}
	(*board).empty = *str++;
	(*board).obstacle = *str++;
	(*board).full = *str;
	return (0);
}

int	populate_header(t_board *board, int fh)
{
	char	str[128];
	char	p;
	int		i;
	int		cols;

	p = 0;
	i = 0;
	while (p != '\n')
	{
		read(fh, &p, 1);
		str[i] = p;
		++i;
	}
	if (fill_attributes(board, str) == -1)
		return (-1);
	read(fh, &p, 1);
	cols = 0;
	while (p != '\n')
	{
		read(fh, &p, 1);
		++cols;
	}
	(*board).columns = cols;
	return (0);
}

int	validate_str(t_board *board, unsigned int *i, \
					unsigned int *rows, unsigned int *cols)
{
	char	p;

	p = (*board).str[*i];
	if (!(p == (*board).empty || p == (*board).obstacle || p == '\n'))
		return (-1);
	if (*cols == ((*board).columns) && p != '\n' && *rows != (*board).rows - 1)
		return (-1);
	if (*cols == ((*board).columns))
	{
		(*board).str[*i] = '\n';
		*cols = -1;
		++*rows;
	}
	++*cols;
	++*i;
	return (0);
}

void	skip_header(char *p, int *fh)
{
	*p = 0;
	while (*p != '\n')
		read(*fh, p, 1);
}

int	populate_str(t_board *board, int fh)
{
	char			p;
	unsigned int	rows;
	unsigned int	cols;
	unsigned int	i;
	int				has_empty;

	skip_header(&p, &fh);
	has_empty = 0;
	rows = 0;
	cols = 0;
	i = 0;
	while (i < (board->columns + 1) * board->rows - 1)
	{
		if (read(fh, &p, 1) == 0 && cols + 1 != (*board).columns)
			return (-1);
		(*board).str[i] = p;
		if (p == (*board).empty)
			has_empty = 1;
		if (validate_str(board, &i, &rows, &cols) == -1)
			return (-1);
	}
	if (!has_empty || read(fh, &p, 1) > 0)
		return (-1);
	return (0);
}
