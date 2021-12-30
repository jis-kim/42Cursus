/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:48:01 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/31 02:50:14 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	invalid_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		while(j < data->map_width)
		{
			if (ft_strchr("01ECP", data->map[i][j]) == 0)
				print_error();
			if ((i == 0 || j == 0 || i == data->map_height - 1 || \
			j == data->map_width - 1) && data->map[i][j] != '1')
				print_error();
		}
	}
}

void	insert_map(int fd, t_data *data)
{
	int	result;
	char	*line;
	int	i;

	data->map = malloc(sizeof(char *) * data->map_height);
	i = 0;
	result = 1;
	if (!data->map)
		print_error();
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (result == -1)
			print_error();
		data->map[i++] = line;
	}
}

void	check_map(int fd, t_data *data)
{
	int	result;
	char	*line;

	result = 1;
	data->map_width = 0;
	data->map_height = 0;
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (result == -1)
			print_error();
		if (data->map_height == 0)
			data->map_width = ft_strlen(line);
		else
			if (data->map_width != ft_strlen(line))
				print_error();
		free(line);
		data->map_height++;
	}
}

void	read_map(char *map_path, t_data *data)
{
	int	fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error();
	check_map(fd, data);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error();
	insert_map(fd, data);
	exit(0);
}
