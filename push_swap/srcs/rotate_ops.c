/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:58:42 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 19:54:26 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack, char name)
{
	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		swap(stack, name);
		return ;
	}
	stack->tail->next = stack->head;
	stack->tail = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = NULL;
	if (name == 'a')
		ft_cmd_add(&stack->cmd_h, "ra");
	else if (name == 'b')
		ft_cmd_add(&stack->cmd_h, "rb");
}

void	reverse_rotate(t_stack *stack, char name)
{
	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		swap(stack, name);
		return ;
	}
	else
	{
		stack->tail->next = stack->head;
		stack->head = stack->tail;
		while (stack->tail->next != stack->head)
			stack->tail = stack->tail->next;
	}
	stack->tail->next = NULL;
	if (name == 'a')
		ft_cmd_add(&stack->cmd_h, "rra");
	else if (name == 'b')
		ft_cmd_add(&stack->cmd_h, "rrb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, ' ');
	rotate(b, ' ');
	ft_cmd_add(&a->cmd_h, "rr");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, ' ');
	reverse_rotate(b, ' ');
	ft_cmd_add(&a->cmd_h, "rrr");
}
