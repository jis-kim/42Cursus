/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:44:21 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 18:28:44 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_operation(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp("sa", str, 3))
		swap(a, 'a');
	else if (!ft_strncmp("sb", str, 3))
		swap(b, 'b');
	else if (!ft_strncmp("ss", str, 3))
		ss(a, b);
	else if (!ft_strncmp("pa", str, 3))
		push(a, b, 'a');
	else if (!ft_strncmp("pb", str, 3))
		push(b, a, 'b');
	else if (!ft_strncmp("ra", str, 3))
		rotate(a, 'a');
	else if (!ft_strncmp("rb", str, 3))
		rotate(b, 'b');
	else if (!ft_strncmp("rr", str, 3))
		rr(a, b);
	else if (!ft_strncmp("rra", str, 4))
		reverse_rotate(a, 'a');
	else if (!ft_strncmp("rrb", str, 4))
		reverse_rotate(b, 'b');
	else if (!ft_strncmp("rrr", str, 4))
		rrr(a, b);
	else
		print_error();
}

int	check_sorted(t_stack *a, t_stack *b)
{
	t_node	*to_compare;
	t_node	*node;
	int		sorted;

	node = a->head;
	sorted = 1;
	if (b->size > 0)
		return (0);
	while (node->next != NULL)
	{
		to_compare = node->next;
		while (to_compare != NULL)
		{
			if (node->num > to_compare->num)
				sorted = 0;
			to_compare = to_compare->next;
		}
		node = node->next;
	}
	return (sorted);
}

void	check_duplication(t_stack *a)
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
			to_compare = to_compare->next;
		}
		node = node->next;
	}
}

void	read_operation(t_stack *a, t_stack *b)
{
	char	*str;
	int		result;

	result = 1;
	while (result > 0)
	{
		result = get_next_line(0, &str);
		if (result == -1)
			print_error();
		if (result == 0)
		{
			free(str);
			break ;
		}
		check_operation(a, b, str);
		free(str);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_cmd	*cmd_h;

	if (argc < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	insert_stack(a, argc, argv);
	check_duplication(a);
	b = ft_calloc(1, sizeof(t_stack));
	cmd_h = ft_calloc(1, sizeof(t_cmd));
	a->cmd_h = cmd_h;
	b->cmd_h = cmd_h;
	read_operation(a, b);
	if (check_sorted(a, b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}
