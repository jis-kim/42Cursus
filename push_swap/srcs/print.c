/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:21:07 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 20:21:03 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	print_command(t_cmd *cmd_h)
{
	t_cmd	*node;

	node = cmd_h;
	while (node)
	{
		if ((node->str) && !ft_strncmp(node->str, "rra", 3))
		{
			if (node->next && !ft_strncmp(node->next->str, "rrb", 3))
			{
				ft_putstr_fd("rrr\n", 1);
				node = node->next->next;
				continue;
			}
		}
		if (node->str)
		{
			ft_putstr_fd(node->str, 1);
			ft_putstr_fd("\n", 1);
		}
		node = node->next;
	}
}
