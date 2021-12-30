/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:43:00 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/31 00:15:14 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char *argv[])
{
	t_data	data;

	file_check(argc, argv);
	read_map(argv[1], &data);
	init_data(&data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 0, key_pressed, &data);

	mlx_loop(data.mlx);
}
