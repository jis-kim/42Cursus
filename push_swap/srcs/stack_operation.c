/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:01:40 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/07 18:25:04 by jiskim           ###   ########.fr       */
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

void	rotate(t_stack *stack)
{
	if (stack->size <= 1)
		return ;
	stack->tail->next = stack->head;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	stack->tail->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->size <= 1)
		return ;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	while (stack->tail->next != stack->head)
		stack->tail = stack->tail->next;
	stack->tail->next = NULL;
}
