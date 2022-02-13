/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:26:18 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/13 22:10:46 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_under_two(t_stack *dst, t_stack *other, int size, int direction)
{
	if (size == 0)
		return ;
	if (dst->name == 'a')
	{
		if (size == 2)
		{
			if (direction == asc && dst->head->num > dst->head->next->num)
				swap(dst, 'a');
			else if (direction == desc && dst->head->num < dst->head->next->num)
				swap(dst, 'a');
		}
	}
	else
	{
		if (size == 2)
		{
			if (direction == asc && other->head->num < other->head->next->num)
				swap(other, 'a');
			else if (direction == desc && other->head->num > other->head->next->num)
				swap(other, 'a');
			push(dst, other, 'b');
			push(dst, other, 'b');
		}
		else
			push(dst, other, 'b');
	}
}

#include <stdio.h>
void	sort_to_a(t_stack *a, t_stack *b, int size, int direction)
{
	int	fst_size;
	int	snd_size;
	int	thd_size;

	if (size <= 2)
	{
		sort_under_two(a, b, size, direction);
		return ;
	}
	fst_size = size / 3;
	snd_size = size / 3;
	thd_size = size / 3  + size % 3;
	sort_to_b(a, b, fst_size, direction);
	sort_to_a(a, b, snd_size, direction);
	while (fst_size > 0 && snd_size > 0)
	{
		fst_size--;
		snd_size--;
		rr(a, b);
	}
	sort_to_b(a, b, thd_size, !direction);
	merge(a, b, size, direction);
}

void	sort_to_b(t_stack *a, t_stack *b, int size, int direction)
{
	int	fst_size;
	int	snd_size;
	int	thd_size;

	if (size <= 2)
	{
		sort_under_two(b, a, size, direction);
		return ;
	}
	fst_size = size / 3;
	snd_size = size / 3;
	thd_size = size / 3 + size % 3;
	sort_to_b(a, b, fst_size, direction);
	sort_to_a(a, b, snd_size, direction);
	while (fst_size > 0 && snd_size > 0)
	{
		fst_size--;
		snd_size--;
		rr(a, b);
	}
	sort_to_a(a, b, thd_size, !direction);
	merge(b, a, size, direction);
}
