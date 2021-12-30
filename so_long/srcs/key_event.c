/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:44:51 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/30 22:45:12 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

static int check_player_movable(int x, int y, t_data *data)
{
	char loc_info;

	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
		return (0);
	loc_info = data->map[y][x];
	return (loc_info != '1');
}

static void check_collectable_enemy(int x, int y, int ch_x, int ch_y, t_data *data)
{
	if(data->map[y + ch_y][x + ch_x] == 'C')
	{
		data->map[y + ch_y][x + ch_x] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->background->img , (x + ch_x) * 64, (y + ch_y) * 64);
		data->col_num--;
	}
	else if(data->map[y + ch_y][x + ch_x] == 'E')
	{
		if(data->col_num <= 0) {
			end_game(1, data);
		}

	}
	else if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->exit->img , x * 64, y * 64);
	}
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
		check_collectable_enemy(player->x, player->y, change_x, change_y, data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, player->img\
		, (player->x += change_x) * 64, (player->y += change_y) * 64);
		printf("%d\n", (++data->move_count));
	}
}

int key_pressed(int keycode, void *args)
{
	if (keycode == 53)
	{
		close_window(args);
		return 1;
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move_player(keycode , (t_data *)args);
	return 1;
}
