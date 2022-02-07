/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:26:03 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/07 12:27:41 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_duplication(t_stack *a)
{
	t_node	*toCompare;
	t_node	*node;

	node = a->head;
	while (node->next != NULL)
	{
		toCompare = node->next;
		while (toCompare != NULL)
		{
			if (node->num == toCompare->num)
				print_error();
			toCompare = toCompare->next;
		}
		node = node->next;
	}
}

void	set_node(t_stack *a, char *splitted)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->num = ft_atoi(splitted);
	if (!a->head)
		a->head = node;
	else
		a->tail->next = node;
	a->tail = node;
	a->size++;
}

void	insert_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	char	**splitted;
	char	**initial;

	i = 0;
	while (argc > ++i)
	{
		splitted = ft_split(argv[i], ' ');
		initial = splitted;
		while (*splitted)
		{
			if (ft_strlen(*splitted) != 0)
				set_node(a, *splitted);
			free(*splitted);
			splitted++;
		}
		free(initial);
	}
}

t_stack	*parse(int argc, char **argv)
{
	t_stack	*a;

	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	insert_stack(a, argc, argv);
	check_duplication(a);
	return (a);
}
