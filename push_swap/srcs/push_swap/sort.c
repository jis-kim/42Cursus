/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:26:18 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 16:24:25 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_a(t_stack *a, t_stack *b, int size, int dir)
{
	int	bottom_size;
	int	top_size;

	if (size <= 5)
	{
		sort_small_chunk(a, b, size, dir);
		return ;
	}
	bottom_size = size / 3;
	top_size = size / 3;
	if (size % 3 == 1)
		top_size++;
	else if (size % 3 == 2)
		bottom_size++;
	sort_to_b(a, b, bottom_size, dir);
	sort_to_a(a, b, bottom_size, dir);
	while (bottom_size-- > 0)
		rr(a, b);
	sort_to_b(a, b, top_size, !dir);
	merge(a, b, size, dir);
}

void	sort_to_b(t_stack *a, t_stack *b, int size, int dir)
{
	int	bottom_size;
	int	top_size;

	if (size <= 2)
	{
		sort_under_two(b, a, size, dir);
		return ;
	}
	bottom_size = size / 3;
	top_size = size / 3;
	if (size % 3 == 1)
		top_size++;
	else if (size % 3 == 2)
		bottom_size++;
	sort_to_b(a, b, bottom_size, dir);
	sort_to_a(a, b, bottom_size, dir);
	while (bottom_size-- > 0)
		rr(a, b);
	sort_to_a(a, b, top_size, !dir);
	merge(b, a, size, dir);
}
