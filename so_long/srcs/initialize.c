/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:09:30 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/16 02:52:19 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
**	put image by map
*/
void show_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;

	char map[9][9] = {
			{'1', '1', '1', '1', '1', '1', '1', '1', '1',},
			{'1', 'P', '0', '0', '0', '0', '0', '0', '1',},
			{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
			{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
			{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
			{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
			{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
			{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
			{'1', '1', '1', '1', '1', '1', '1', '1', '1',}
		};

	while (i < 9) {
		j = 0;
		while (j < 9) {
			if (map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player->img, j*64, i*64);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->obstacle->img, j*64, i*64);
			else
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->background->img, j*64, i*64);
			j++;
		}
		i++;
	}
}

/**
 * set images
 * player, background, obstacle, enemy, goal
 */
void set_component(t_data *data)
{
	t_component *c;
	int size = IMG_SIZE;

	c = data->background;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);
	c = data->player;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);
	c = data->obstacle;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);

	show_map(data);
}

void init_data(t_data *data)
{
	t_component player;
	t_component background;
	t_component obstacle;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 576, 576, "so_long");
	data->player = &player;
	data->background = &background;
	data->obstacle = &obstacle;
	data->player->path = CHAR_PATH;
	data->background->path = BACK_PATH;
	data->obstacle->path = OB_PATH;

	//char map[9][9] = {
	//	{'1', '1', '1', '1', '1', '1', '1', '1', '1',},
	//	{'1', 'P', '0', '0', '0', '0', '0', '0', '1',},
	//	{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
	//	{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
	//	{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
	//	{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
	//	{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
	//	{'1', '0', '0', '0', '0', '0', '0', '0', '1',},
	//	{'1', '1', '1', '1', '1', '1', '1', '1', '1',}
	//};

	//data->map = malloc(sizeof(char) * 9);
	//int i = 0;
	//while (i < 9)
	//{
	//	data->map[i] = malloc(sizeof(char) * 9);
	//}
	//int j = 0;
	//i = 0;
	//while (i)
	//data->map_height = 9;
	//data->map_width = 9;

	set_component(data);
}
