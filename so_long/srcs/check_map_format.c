/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:06:05 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/04 02:41:09 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_element_num(int element[])
{
	int	i;

	i = 0;
	if (element[hash('E')] == 1 && element[hash('C')] > 0 && \
	element[hash('P')] == 1)
		return ;
	print_error("Invalid map.");
}

static void	check_valid_component(t_data *data, int *element, int x, int y)
{
	char	info;

	info = data->map[y][x];
	if ((y == 0 || x == 0 || y == data->map_height - 1 || \
	x == data->map_width - 1) && info != '1')
		print_error("Invalid map1.");
	else if (ft_strchr("01ECP", info) == 0)
		print_error("Invalid map2.");
	else if (info == 'C' || info == 'E' || info == 'P')
		element[hash(info)]++;
}

void	check_valid_format(t_data *data)
{
	int		i;
	int		j;
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
			check_valid_component(data, element, j, i);
			j++;
		}
		i++;
	}
	check_element_num(element);
	data->col_num = element[hash('C')];
}
