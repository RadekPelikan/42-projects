/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljiriste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:52:04 by ljiriste          #+#    #+#             */
/*   Updated: 2023/06/26 18:06:13 by ljiriste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/board.h"

int	is_in_bsq(t_bsq bsq, unsigned int row, unsigned int column)
{
	return (bsq.row <= row && row < bsq.row + bsq.size
		&& bsq.column < column + bsq.size && column <= bsq.column);
}

void	draw_bsq_to_board(t_board board, t_bsq bsq)
{
	unsigned int	row;
	unsigned int	column;

	row = 0;
	while (row < board.rows)
	{
		column = 0;
		while (column < board.columns)
		{
			if (is_in_bsq(bsq, row, column))
				board.str[row * (board.columns + 1) + column] = board.full;
			++column;
		}
		++row;
	}
	return ;
}
