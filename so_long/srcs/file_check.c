/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:28:04 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/03 01:36:16 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(void)
{
	printf("Error!\n");
	exit(0);
}

void	file_check(int argc, char *argv[])
{
	char	*map_path;
	char	*extension;
	int		i;

	if (argc != 2)
		print_error();
	map_path = argv[1];
	extension = ".ber";
	i = 0;
	while (*(map_path) != '\0')
		map_path++;
	map_path -= 5;
	while (extension[i] != '\0')
	{
		if (map_path[i] != extension[i])
			print_error();
		i++;
	}
}
