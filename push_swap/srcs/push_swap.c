/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:26:34 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/14 02:56:34 by jiskim           ###   ########.fr       */
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

	if (argc < 2)
		return (0);
	a = parse(argc, argv);
	b = ft_calloc(1, sizeof(t_stack));
	b->name = 'b';
	push_swap(a, b);

	//t_node *a_node;
	//a_node = a->head;
	//while (a_node)
	//{
	//	ft_putnbr_fd(a_node->num, 1);
	//	ft_putstr_fd("->", 1);
	//	a_node = a_node->next;
	//}
	//ft_putstr_fd("\n", 1);
}
