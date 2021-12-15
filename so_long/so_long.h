/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:44:49 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/16 02:45:31 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define KEY_ESC 53;
#define IMG_SIZE 64;

#define CHAR_PATH "./img/chadul_front_64.xpm";
#define BACK_PATH "./img/grass_64.xpm";
#define OB_PATH "./img/cliff_64.xpm";

#include "./mlx/mlx.h"
#include <stdlib.h>

typedef struct s_component
{
	char	*path;
	void	*img;
	int		x;
	int		y;
	int		recent_key;
} t_component;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	t_component	*player;
	t_component	*background;
	t_component	*obstacle;
	char		**map;
	int			map_width;
	int			map_height;
} t_data;


int	close_window(void *args);
int key_pressed(int keycode, void *args);
void init_data(t_data *data);

#endif
