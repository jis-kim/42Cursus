/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:09:30 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/17 20:26:31 by jiskim           ###   ########.fr       */
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
	t_component *component;

	i = 0;
	j = 0;

	strcpy(data->map[0], "111111111");
	strcpy(data->map[1], "1P0000001");
	strcpy(data->map[2], "100000001");
	strcpy(data->map[3], "100000001");
	strcpy(data->map[4], "100000001");
	strcpy(data->map[5], "100000001");
	strcpy(data->map[6], "100000001");
	strcpy(data->map[7], "100000001");
	strcpy(data->map[8], "111111111");

	while (i < 9) {
		j = 0;
		while (j < 9) {
			if (data->map[i][j] == '1')
				component = data->obstacle;
			else{
				component = data->background;
				if (data->map[i][j] == 'P')
				{
					mlx_put_image_to_window(data->mlx, data->mlx_win, component->img, j*64, i*64);
					component = data->player;
					component->x = j;
					component->y = i;
				}
			}
			mlx_put_image_to_window(data->mlx, data->mlx_win, component->img, j*64, i*64);
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
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 576, 576, "so_long");
	data->player = malloc(sizeof(t_component));
	data->background = malloc(sizeof(t_component));
	data->obstacle = malloc(sizeof(t_component));
	data->player->path = CHAR_PATH;
	data->background->path = BACK_PATH;
	data->obstacle->path = OB_PATH;
	data->map = malloc(sizeof(char *) * 9);
	for (int i = 0; i < 9; i++)
		data->map[i] = malloc(sizeof(char) * 10);
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
	data->map_height = 9;
	data->map_width = 9;

	set_component(data);
}
