/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:26:34 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/07 18:21:20 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_node	*a_node;

	if (argc < 2)
		return (0);
	a = parse(argc, argv);

	a_node = a->head;
	// list 조회

	while (a_node != NULL)
	{
		printf("%d->", a_node->num);
		a_node = a_node->next;
	}

	printf("\n");
	reverse_rotate(a);

	a_node = a->head;
	// list 조회

	while (a_node != NULL)
	{
		printf("%d->", a_node->num);
		a_node = a_node->next;
	}
}
