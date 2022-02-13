/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:58:42 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/10 18:45:38 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
