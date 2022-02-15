/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:26:34 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 20:20:38 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
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
