/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:28:04 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/04 01:06:13 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	file_check(int argc, char *argv[])
{
	char	*map_path;
	char	*extension;
	int		i;

	if (argc != 2)
		print_error("Too many or less arguments.");
	map_path = argv[1];
	extension = ".ber";
	i = 0;
	while (*(map_path) != '\0')
		map_path++;
	map_path -= 4;
	while (extension[i] != '\0')
	{
		if (map_path[i] != extension[i])
			print_error("File must be end with '.ber'.");
		i++;
	}
}
