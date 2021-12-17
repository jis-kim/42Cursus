/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:44:51 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/17 20:28:44 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

static int check_player_movable(int x, int y, t_data *data)
{
	char loc_info;

	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
		return (0);
	loc_info = data->map[x][y];
	return (loc_info == '0');
}

static void move_player(int keycode, t_data *data)
{
	int change_x;
	int change_y;
	t_component *player;
	t_component *background;

	player = data->player;
	background = data->background;
	change_x = 0;
	change_y = 0;
	if(keycode == 13) //up
		change_y = -1;
	else if(keycode == 0) //a left
		change_x = -1;
	else if(keycode == 1) //s down
		change_y = 1;
	else
		change_x = 1; //d right
	if (check_player_movable(player->x + change_x, player->y + change_y, data))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, background->img\
		, (player->x) * 64,  (player->y) * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, player->img\
		, (player->x += change_x) * 64, (player->y += change_y) * 64);
		printf("player is (%d , %d)\n", player->x, player->y);
	}
}

int key_pressed(int keycode, void *args)
{
	if (keycode == 53)
	{
		close_window(args); //ㅎㅎ 이게 아니야?ㅎㅎ
		return 1;
	}
	//if (keycode == 13) //W - up
	//else if (keycode == 0) //A - left
	//else if (keycode == 1) //S - down
	//else if (keycode == 2) //D - right
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move_player(keycode , (t_data *)args);
	return 1;
}
