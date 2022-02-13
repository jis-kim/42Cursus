/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:21:07 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/14 01:52:34 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	print_command(char *str)
{
	if (*str)
	{
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
	}
}
