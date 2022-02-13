/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:01:40 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/11 01:42:43 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->head)
		return ;
	else if (stack->head == stack->tail)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = tmp->next->next;
	stack->head->next = tmp;
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (from->size == 0)
		return ;
	if (from->head == from->tail)
	{
		from->head->next = to->head;
		to->head = from->head;
		from->head = NULL;
	}
	else
	{
		tmp = from->head->next;
		from->head->next = to->head;
		to->head = from->head;
		from->head = tmp;
	}
	from->size--;
	to->size++;
}
