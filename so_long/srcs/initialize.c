/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:09:30 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/03 00:53:20 by jiskim           ###   ########.fr       */
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
	while (i < data->map_height) {
		j = 0;
		while (j < data->map_width) {
			component = data->background;
			mlx_put_image_to_window(data->mlx, data->mlx_win, component->img, j*64, i*64);
			if (data->map[i][j] == 'P')
			{
				component = data->player;
				component->x = j;
				component->y = i;
			}
			else if (data->map[i][j] == 'C')
				component = data->collectable;
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
	data->player = ft_calloc(sizeof(t_component));
	data->background = ft_calloc(sizeof(t_component));
	data->obstacle = ft_calloc(sizeof(t_component));
	data->collectable = ft_calloc(sizeof(t_component));
	data->enemy = ft_calloc(sizeof(t_component));
	data->exit = ft_calloc(sizeof(t_component));
}

void init_data(t_data *data)
{

	data_mem_allocate(data);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_width * 64, data->map_height * 64, "so_long");
	data->player->path = CHAR_PATH;
	data->background->path = BACK_PATH;
	data->obstacle->path = OB_PATH;
	data->collectable->path = COL_PATH;
	data->exit->path = EXIT_PATH;
	data->collectable->path = COL_PATH;
	data->move_count = 0;
	set_component(data);
}
