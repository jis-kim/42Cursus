/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:09:30 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/30 21:17:25 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
**	put image by map
*/
static void show_map(t_data *data)
{
	int i;
	int j;
	t_component *component;

	i = 0;
	j = 0;

	strcpy(data->map[0], "111111111");
	strcpy(data->map[1], "1P0000001");
	strcpy(data->map[2], "10000C001");
	strcpy(data->map[3], "1000000E1");
	strcpy(data->map[4], "100000001");
	strcpy(data->map[5], "1000C0001");
	strcpy(data->map[6], "100000001");
	strcpy(data->map[7], "100000001");
	strcpy(data->map[8], "111111111");

	while (i < 9) {
		j = 0;
		while (j < 9) {
			component = data->background;
			mlx_put_image_to_window(data->mlx, data->mlx_win, component->img, j*64, i*64);
			if (data->map[i][j] == 'P')
			{
				component = data->player;
				component->x = j;
				component->y = i;
			}
			else if (data->map[i][j] == 'C'){
				component = data->collectable;
				data->col_num++;
			}
			else if (data->map[i][j] == 'E')
				component = data->exit;
			else if (data->map[i][j] == '1')
				component = data->obstacle;
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
static void set_component(t_data *data)
{
	t_component *c;
	int size = IMG_SIZE;

	c = data->background;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);
	c = data->player;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);
	c = data->obstacle;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);
	c = data->collectable;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);
	c = data->exit;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);

	show_map(data);
}

static void data_mem_allocate(t_data *data)
{
	data->player = malloc(sizeof(t_component));
	data->background = malloc(sizeof(t_component));
	data->obstacle = malloc(sizeof(t_component));
	data->collectable = malloc(sizeof(t_component));
	data->enemy = malloc(sizeof(t_component));
	data->exit = malloc(sizeof(t_component));
		data->map = malloc(sizeof(char *) * 9);
	for (int i = 0; i < 9; i++)
		data->map[i] = malloc(sizeof(char) * 10);
}

void init_data(t_data *data)
{

	data_mem_allocate(data);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 576, 576, "so_long");
	data->player->path = CHAR_PATH;
	data->background->path = BACK_PATH;
	data->obstacle->path = OB_PATH;
	data->collectable->path = COL_PATH;
	data->exit->path = EXIT_PATH;
	data->collectable->path = COL_PATH;
	data->map_height = 9;
	data->map_width = 9;
	data->move_count = 0;
	data->col_num = 0;
	set_component(data);
}
