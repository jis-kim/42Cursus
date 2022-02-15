/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:26:56 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 19:47:38 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_cmd_add(t_cmd **head, char *str)
{
	t_cmd	*tmp;
	t_cmd	*new;

	tmp = *head;
	new = ft_calloc(1, sizeof(t_cmd));
	new->str = ft_strdup(str);
	if (!*head)
	{
		*head = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_free_cmd(t_cmd	*cmd)
{
	if (!cmd)
		return ;
	free(cmd->str);
	free(cmd);
}
