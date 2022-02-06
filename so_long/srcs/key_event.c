/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:44:51 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/04 14:25:41 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_player_movable(int x, int y, t_data *data)
{
	char	loc_info;

	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
		return (0);
	loc_info = data->map[y][x];
	return (loc_info != '1');
}

static void	player_pass_exit(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->exit->img, x * 64, y * 64);
	}
}

static void	check_finish(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->background->img, (x) * 64, (y) * 64);
		data->col_num--;
	}
	else if (data->map[y][x] == 'E')
	{
		if (data->col_num <= 0)
			end_game(1, data);
	}
}

static void	move_player(int keycode, t_data *data)
{
	int			change_x;
	int			change_y;
	t_component	*player;

	player = data->player;
	change_x = 0;
	change_y = 0;
	if (keycode == KEY_W)
		change_y = -1;
	else if (keycode == KEY_A)
		change_x = -1;
	else if (keycode == KEY_S)
		change_y = 1;
	else
		change_x = 1;
	if (check_player_movable(player->x + change_x, player->y + change_y, data))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->background->img, (player->x) * 64, (player->y) * 64);
		check_finish(player->x + change_x, player->y + change_y, data);
		player_pass_exit(player->x, player->y, data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, player->img, \
		(player->x += change_x) * 64, (player->y += change_y) * 64);
		printf("%d\n", (++data->move_count));
	}
}

int	key_pressed(int keycode, void *args)
{
	if (keycode == KEY_ESC)
	{
		close_window(args);
		return (1);
	}
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		move_player(keycode, (t_data *)args);
	return (1);
}
