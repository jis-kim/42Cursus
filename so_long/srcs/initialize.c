/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:09:30 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/04 02:23:39 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_image(t_data *data, t_component *c)
{
	int	size;

	size = IMG_SIZE;
	c->img = mlx_xpm_file_to_image(data->mlx, c->path, &size, &size);
	if (!(c->img))
		print_error("Invalid image.");
}

/**
 * set images
 * player, background, obstacle, enemy, goal
 */
static void	set_component(t_data *data)
{
	set_image(data, data->background);
	set_image(data, data->player);
	set_image(data, data->obstacle);
	set_image(data, data->collectable);
	set_image(data, data->exit);
}

static void	data_mem_allocate(t_data *data)
{
	data->player = ft_calloc(sizeof(t_component));
	data->background = ft_calloc(sizeof(t_component));
	data->obstacle = ft_calloc(sizeof(t_component));
	data->collectable = ft_calloc(sizeof(t_component));
	data->exit = ft_calloc(sizeof(t_component));
}

void	init_data(t_data *data)
{
	data_mem_allocate(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error("mlx initialize fail.");
	data->mlx_win = mlx_new_window(data->mlx, data->map_width * 64, \
	data->map_height * 64, "so_long");
	if (!data->mlx_win)
		print_error("mlx window initialize fail.");
	data->player->path = CHAR_PATH;
	data->background->path = BACK_PATH;
	data->obstacle->path = OB_PATH;
	data->collectable->path = COL_PATH;
	data->exit->path = EXIT_PATH;
	data->move_count = 0;
	set_component(data);
}
