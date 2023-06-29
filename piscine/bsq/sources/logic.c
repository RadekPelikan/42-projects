/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljiriste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:23:51 by ljiriste          #+#    #+#             */
/*   Updated: 2023/06/26 17:49:19 by ljiriste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/umatrix.h"
#include "../headers/board.h"

// Transforms input matrix in the "count_left" form
// to the "max_top_right" form
//
// The "max_top_right" form assigns every cell of
// the original board the size of the biggest square
// possible, of which the cell is the top right corner
//
// Example
//
//	cl form		mtr form
//
//	123012		111011
//	101230		101120
//	120123	->	110111
//	101201		101201
//	101234		101111
//	
void	cl_mtr_transform(t_umatrix m)
{
	unsigned int	row;
	unsigned int	column;
	unsigned int	l;
	unsigned int	min;

	row = 0;
	while (row < m.rows)
	{
		column = 0;
		while (column < m.columns)
		{
			l = 1;
			min = *get_el(m, row, column);
			while (l <= min && l + row < m.rows)
				if (*get_el(m, row + (l++), column) < min)
					min = *get_el(m, row + l - 1, column);
			if (l + row == m.rows && l <= min)
				++l;
			*get_el(m, row, column++) = l - 1;
		}
		++row;
	}
	return ;
}

// Finds the top most left most maximum value (bsq) in t_umatrix
t_bsq	find_bsq(t_umatrix m)
{
	unsigned int	row;
	unsigned int	column;
	t_bsq			bsq;

	bsq.row = 0;
	bsq.column = 0;
	bsq.size = 0;
	row = 0;
	while (row < m.rows)
	{
		column = 0;
		while (column < m.columns)
		{
			if (*get_el(m, row, column) > bsq.size)
			{
				bsq.size = *get_el(m, row, column);
				bsq.row = row;
				bsq.column = column;
			}
			++column;
		}
		++row;
	}
	return (bsq);
}
