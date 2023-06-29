/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljiriste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:14:56 by ljiriste          #+#    #+#             */
/*   Updated: 2023/06/26 15:32:07 by ljiriste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

// Encodes the position of right top corner
// of a square and its size
struct s_bsq
{
	unsigned int	size;
	unsigned int	row;
	unsigned int	column;
};

struct s_char_matrix
{
	unsigned int	rows;
	unsigned int	columns;
	char			*str;
	char			empty;
	char			obstacle;
	char			full;
};

typedef struct s_char_matrix	t_board;
typedef struct s_bsq			t_bsq;

int		is_in_bsq(t_bsq bsq, unsigned int row, unsigned int column);
void	draw_bsq_to_board(t_board board, t_bsq bsq);

#endif
