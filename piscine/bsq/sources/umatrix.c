/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   umatrix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljiriste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:57:26 by ljiriste          #+#    #+#             */
/*   Updated: 2023/06/26 17:05:28 by ljiriste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "../headers/umatrix.h"

// Returns an uninitialized matrix
t_umatrix	create_matrix(unsigned int rows, unsigned int columns)
{
	t_umatrix	new_matrix;

	if (UINT_MAX / rows / sizeof(unsigned int) > columns)
		new_matrix.array = malloc(rows * columns * sizeof(unsigned int));
	else
		new_matrix.array = NULL;
	new_matrix.rows = rows;
	new_matrix.columns = columns;
	return (new_matrix);
}

// Returns "count_left" (cl) representation of board
//
// "count_left" representation assigns each
// cell the number of consecutive "empty" characters
// to the left (counting the cell itself)
//
// Example:
// empty char		'.'
// obstacle char	'o'
//
//	board		cl_matrix
//
//	...o..		123012
//	.o...o		101230
//	..o...	->	120123
//	.o..o.		101201
//	.o....		101234
//
t_umatrix	board_to_cl_matrix(t_board board)
{
	t_umatrix		matrix;
	unsigned int	i;
	unsigned int	empty_counter;

	matrix = create_matrix(board.rows, board.columns);
	if (!matrix.array)
		return (matrix);
	i = 0;
	empty_counter = 0;
	while (*board.str == board.empty || *board.str == board.obstacle
		|| *board.str == '\n')
	{
		++empty_counter;
		if (*board.str != board.empty)
			empty_counter = 0;
		if (*board.str != '\n')
			matrix.array[i++] = empty_counter;
		++board.str;
	}
	if (*board.str != '\0')
	{
		free(matrix.array);
		matrix.array = NULL;
	}
	return (matrix);
}

unsigned int	*get_el(t_umatrix m, unsigned int row, unsigned int column)
{
	return (&m.array[m.columns * row + column]);
}
