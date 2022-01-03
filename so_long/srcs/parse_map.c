/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:48:01 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/04 02:40:38 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	insert_map(int fd, t_data *data)
{
	int		result;
	char	*line;
	int		i;

	data->map = ft_calloc(sizeof(char *) * data->map_height);
	i = 0;
	result = 1;
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (result == -1)
			print_error("map read fail.");
		if (result == 0 && line[0] == '\0')
		{
			free(line);
			return ;
		}
		data->map[i++] = line;
	}
}

static void	check_map_length(int fd, t_data *data)
{
	int		result;
	char	*line;

	result = 1;
	data->map_width = 0;
	data->map_height = 0;
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (result == -1)
			print_error("map read fail.");
		if (result == 0 && line[0] == '\0')
		{
			free(line);
			return ;
		}
		if (data->map_height == 0)
			data->map_width = ft_strlen(line);
		else
			if (data->map_width != (int)ft_strlen(line))
				print_error("map is not rectangular.");
		free(line);
		data->map_height++;
	}
}

void	read_map(char *map_path, t_data *data)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error(strerror(errno));
	check_map_length(fd, data);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error(strerror(errno));
	insert_map(fd, data);
	close(fd);
	check_valid_format(data);
}
