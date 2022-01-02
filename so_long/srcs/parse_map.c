/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:48:01 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/03 01:23:12 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_element_num(int element[])
{
	int	i;

	i = 0;
	if (element[hash('E')] == 1 && element[hash('C')] > 0 && \
	element[hash('P')] == 1)
		return ;
	print_error();
}

void	invalid_map(t_data *data)
{
	int		i;
	int		j;
	char	info;
	int		element[3];

	i = 0;
	while (i < 3)
		element[i++] = 0;
	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			info = data->map[i][j];
			if ((i == 0 || j == 0 || i == data->map_height - 1 || \
			j == data->map_width - 1) && info != '1')
				print_error();
			else if (ft_strchr("01ECP", info) == 0)
				print_error();
			else if (info == 'C' || info == 'E' || info == 'P')
				element[hash(info)]++;
			j++;
		}
		i++;
	}
	check_element_num(element);
	data->col_num = element[hash('C')];
}

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
			print_error();
		data->map[i++] = line;
	}
}

void	check_map_length(int fd, t_data *data)
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
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error();
	check_map_length(fd, data);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error();
	insert_map(fd, data);
	close(fd);
	invalid_map(data);
}
