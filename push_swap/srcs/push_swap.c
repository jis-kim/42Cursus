/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:26:34 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/07 02:54:09 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_node	*a_node;

	if (argc < 2)
		print_error();
	a = parse(argc, argv);

	a_node = a->head;
	// list 조회
	while (a_node != NULL)
	{
		printf("%d->", a_node->num);
		a_node = a_node->next;
	}
	exit(1);
}
