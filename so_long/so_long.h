/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:44:49 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/31 00:20:51 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define KEY_ESC 53;
#define IMG_SIZE 64;

#define CHAR_PATH "/Users/jisukim/42Cursus/so_long/img/chadul_front_64.xpm";
#define BACK_PATH "/Users/jisukim/42Cursus/so_long/img/grass_64.xpm";
#define OB_PATH "/Users/jisukim/42Cursus/so_long/img/hole.xpm";
#define EXIT_PATH "/Users/jisukim/42Cursus/so_long/img/pipe.xpm";
#define COL_PATH "/Users/jisukim/42Cursus/so_long/img/bell_64.xpm";
#define SUCCESS_MSG_PATH "/Users/jisukim/42Cursus/so_long/img/success_message.xpm"
#define FAIL_MSG_PATH "/Users/jisukim/42Cursus/so_long/img/fail_message.xpm"


#include "./mlx/mlx.h"
#include "./srcs/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h> //제외필수

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
	t_component	*collectable;
	t_component	*exit;
	t_component	*enemy;
	char		**map;
	int			map_width;
	int			map_height;
	int			move_count;
	int			col_num;
} t_data;


int	close_window(void *args);
int	key_pressed(int keycode, void *args);
void	init_data(t_data *data);
void	end_game(int success, t_data *data);
void	print_error();
void	file_check(int argc, char *argv[]);
void	read_map(char *map_path, t_data *data);
int	get_next_line(int fd, char **line);

#endif
