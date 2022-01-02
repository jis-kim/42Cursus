/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:33:41 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/03 01:31:34 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	hash(char c)
{
	return ((int)c % 3);
}

void	*ft_calloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		print_error();
	return (ptr);
}

int	close_window(void *args)
{
	t_data	*data;

	data = (t_data *)(args);
	exit(0);
	return (0);
}

int	nothing(int keycode, void *args)
{
	t_data	*data;

	if (keycode == 53)
	{
		close_window(args);
		return (1);
	}
	data = (t_data *)args;
	return (0);
}

void	end_game(int success, t_data *data)
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;

	width = 308;
	height = 100;
	x = (data->map_width * 64 - width) / 2;
	y = data->map_height * 64 - height;
	mlx_hook(data->mlx_win, 2, 0, nothing, data);
	if (success)
		img = mlx_xpm_file_to_image(data->mlx, SUCCESS_MSG_PATH, \
		&width, &height);
	else
		img = mlx_xpm_file_to_image(data->mlx, FAIL_MSG_PATH, &width, &height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x, y);
}
