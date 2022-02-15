/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:26:34 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 20:54:27 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_prev(t_stack *a)
{
	int	max_val;

	if (a->head->num < a->head->next->num && a->head->next->num < a->tail->num)
		return;
	max_val = max(a->head->num, a->head->next->num, a->tail->num);
	if (0 == max_val)
	{
		rotate(a, 'a');
		if (a->head->num < a->head->next->num)
			return ;
	}
	else if (1== max_val)
	{
		reverse_rotate(a, 'a');
		if (a->head->num < a->head->next->num)
			return ;
	}
	swap(a, 'a');
}

void	sort_lt_six(t_stack *a, t_stack *b, int size)
{
	if (size <= 2)
		sort_under_two(a, b, size, asc);
	else if (size == 3)
		sort_three_prev(a);
	else
	{
		sort_under_two(b, a, 2, desc);
		if (size == 4)
			sort_under_two(a, b, 2, asc);
		else
			sort_three_prev(a);
		small_merge(a, b, size, asc);
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_lt_six(a, b, a->size);
	else
		sort_to_a(a, b, a->size, asc);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_cmd	*cmd_h;

	if (argc < 2)
		return (0);
	a = parse(argc, argv);
	b = ft_calloc(1, sizeof(t_stack));
	b->name = 'b';
	cmd_h = ft_calloc(1, sizeof(t_cmd));
	a->cmd_h = cmd_h;
	b->cmd_h = cmd_h;
	push_swap(a, b);
	print_command(a->cmd_h);
	// t_node *a_node;
	// a_node = a->head;

	// ft_putendl_fd("before", 1);
	// ft_putendl_fd("a", 1);
	// while (a_node)
	// {
	// 	ft_putnbr_fd(a_node->num, 1);
	// 	ft_putstr_fd("->", 1);
	// 	a_node = a_node->next;
	// }
	// ft_putstr_fd("\n", 1);

	// t_node *b_node;
	// b_node = b->head;
	// ft_putendl_fd("b", 1);
	// while (b_node)
	// {
	// 	ft_putnbr_fd(b_node->num, 1);
	// 	ft_putstr_fd("->", 1);
	// 	b_node = b_node->next;
	// }
	// ft_putstr_fd("\n", 1);

	// ft_putendl_fd("after", 1);
	// reverse_rotate(a,  'a');
	// ft_putendl_fd("a", 1);
	// a_node = a->head;
	// while (a_node)
	// {
	// 	ft_putnbr_fd(a_node->num, 1);
	// 	ft_putstr_fd("->", 1);
	// 	a_node = a_node->next;
	// }
	// ft_putstr_fd("\n", 1);

	// b_node = b->head;
	// ft_putendl_fd("b", 1);
	// while (b_node)
	// {
	// 	ft_putnbr_fd(b_node->num, 1);
	// 	ft_putstr_fd("->", 1);
	// 	b_node = b_node->next;
	// }
	// ft_putstr_fd("\n", 1);
}
