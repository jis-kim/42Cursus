/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:26:03 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 21:00:18 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_atoi(const char *str)
{
	int					sign;
	int					i;
	unsigned long long	ai;

	sign = 1;
	ai = 0;
	while (*str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	i = 0;
	while (*str && ++i < 11)
	{
		if (*str < '0' || *str > '9')
			print_error();
		ai = (10 * ai) + (*str++ - '0');
	}
	if (*str || (sign == 1 && ai > INT_MAX) || (sign == -1 && ai > 2147483648))
		print_error();
	return (ai * sign);
}

void	check_duplication_sorted(t_stack *a)
{
	t_node	*to_compare;
	t_node	*node;
	int		sorted;

	node = a->head;
	sorted = 1;
	while (node->next != NULL)
	{
		to_compare = node->next;
		while (to_compare != NULL)
		{
			if (node->num == to_compare->num)
				print_error();
			if (node->num > to_compare->num)
				sorted = 0;
			to_compare = to_compare->next;
		}
		node = node->next;
	}
	if (sorted)
		exit(0);
}

void	set_node(t_stack *a, char *splitted)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->num = ft_ps_atoi(splitted);
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
		if (!*argv[i])
			print_error();
		splitted = ft_split(argv[i], ' ');
		if (!*splitted)
			print_error();
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
	check_duplication_sorted(a);
	a->name = 'a';
	return (a);
}
