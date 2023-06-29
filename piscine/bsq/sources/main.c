/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:25:12 by ljiriste          #+#    #+#             */
/*   Updated: 2023/06/28 20:25:52 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../headers/board.h"
#include "../headers/umatrix.h"
#include "../headers/logic.h"
#include "../headers/out.h"
#include "../headers/load.h"

// char *pathname = "./resources/map.bsq";

void	solve_file(char *file_name)
{
	t_board		board;
	t_umatrix	matrix;
	t_bsq		bsq;

	board = load_map(file_name);
	if (board.columns == 0)
	{
		print_error("map error\n");
		return ;
	}
	matrix = board_to_cl_matrix(board);
	cl_mtr_transform(matrix);
	bsq = find_bsq(matrix);
	draw_bsq_to_board(board, bsq);
	print_str(board.str);
	print_str("\n");
	free(board.str);
	free(matrix.array);
	return ;
}

void	std_input_mode(void)
{
	char	buffer[1024];
	int		size;

	size = 1;
	while (size > 0)
	{
		size = read(0, buffer, 1024);
		buffer[size - 1] = '\0';
		if (size > 0)
			solve_file(buffer);
	}
	return ;
}

int	main(int argc, char **argv)
// int	main(void)
{
	int			i;

	i = 1;
	if (argc == 1)
		std_input_mode();
	else
		while (i < argc)
			solve_file(argv[i++]);
	return (0);
}
