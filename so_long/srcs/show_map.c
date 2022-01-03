/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 02:23:02 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/04 02:35:04 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_image(t_data *data, char c, int x, int y)
{
	t_component	*component;

	component = data->background;
	mlx_put_image_to_window(data->mlx, data->mlx_win, component->img, \
	x * 64, y * 64);
	if (c == 'P')
	{
		component = data->player;
		component->x = x;
		component->y = y;
	}
	else if (c == 'C')
		component = data->collectable;
	else if (c == 'E')
		component = data->exit;
	else if (c == '1')
		component = data->obstacle;
	mlx_put_image_to_window(data->mlx, data->mlx_win, component->img, \
	x * 64, y * 64);
}

void	show_map(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			put_image(data, data->map[i][j], j, i);
			j++;
		}
		i++;
	}
}
