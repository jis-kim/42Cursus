/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:43:00 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/17 19:41:07 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(void)
{
	t_data data;
	init_data(&data);

	/*
		1. when click red button
		2. esc press
		3. WASD key press
	*/
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 0, key_pressed, &data);

	mlx_loop(data.mlx);
}
