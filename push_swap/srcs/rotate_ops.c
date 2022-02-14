/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:58:42 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/14 19:41:10 by jiskim           ###   ########.fr       */
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
		print_command("ra");
	else if (name == 'b')
		print_command("rb");
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
		print_command("rra");
	else if (name == 'b')
		print_command("rrb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, ' ');
	rotate(b, ' ');
	print_command("rr");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, ' ');
	reverse_rotate(b, ' ');
	print_command("rrr");
}
