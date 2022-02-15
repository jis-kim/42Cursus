/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:01:40 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 19:54:09 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack, char name)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = tmp->next->next;
	stack->head->next = tmp;
	if (stack->size == 2)
		stack->tail = tmp;
	stack->tail->next = NULL;
	if (name == 'a')
		ft_cmd_add(&stack->cmd_h, "sa");
	else if (name == 'b')
		ft_cmd_add(&stack->cmd_h, "sb");
}

void	push(t_stack *dst, t_stack *other, char name)
{
	t_node	*tmp;

	if (other->size == 0)
		return ;
	tmp = other->head->next;
	other->head->next = dst->head;
	dst->head = other->head;
	other->head = tmp;
	if (other->size == 1)
		other->tail = NULL;
	if (dst->tail == NULL)
		dst->tail = dst->head;
	dst->tail->next = NULL;
	other->size--;
	dst->size++;
	if (name == 'a')
		ft_cmd_add(&dst->cmd_h, "pa");
	else if (name == 'b')
		ft_cmd_add(&dst->cmd_h, "pb");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, ' ');
	swap(b, ' ');
	ft_cmd_add(&a->cmd_h, "ss");
}
