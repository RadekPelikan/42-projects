/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   umatrix.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljiriste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:46:23 by ljiriste          #+#    #+#             */
/*   Updated: 2023/06/26 17:58:20 by ljiriste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UMATRIX_H
# define UMATRIX_H

# include "board.h"

struct s_uint_matrix
{
	unsigned int	rows;
	unsigned int	columns;
	unsigned int	*array;
};

typedef struct s_uint_matrix	t_umatrix;

t_umatrix		create_matrix(unsigned int rows, unsigned int columns);
unsigned int	*get_el(t_umatrix m, unsigned int row, unsigned int column);
t_umatrix		board_to_cl_matrix(t_board board);

#endif
