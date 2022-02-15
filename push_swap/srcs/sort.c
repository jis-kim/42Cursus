/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:26:18 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 13:43:26 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_under_two(t_stack *dst, t_stack *other, int size, int dir)
{
	if (size == 0)
		return ;
	if (dst->name == 'a')
	{
		if (size == 2)
		{
			if (dir == asc && dst->head->num > dst->head->next->num)
				swap(dst, 'a');
			else if (dir == desc && dst->head->num < dst->head->next->num)
				swap(dst, 'a');
		}
	}
	else
	{
		if (size == 2)
		{
			if (dir == asc && other->head->num < other->head->next->num)
				swap(other, 'a');
			else if (dir == desc && other->head->num > other->head->next->num)
				swap(other, 'a');
			push(dst, other, 'b');
		}
		push(dst, other, 'b');
	}
}

void	sort_three(t_stack *a, t_stack *b, int dir)
{
	int	fst;
	int	snd;
	int	thd;
	int	min_or_max;

	fst = a->head->num;
	snd = a->head->next->num;
	thd = a->head->next->next->num;
	if (dir == asc)
		min_or_max = max(fst, snd, thd);
	else
		min_or_max = min(fst, snd, thd);
	if (min_or_max == 2)
	{
		if ((!dir && fst > snd) || (dir && fst < snd))
			swap(a, 'a');
		return ;
	}
	if (min_or_max == 0)
		swap(a, 'a');
	push(b, a, 'b');
	swap(a, 'a');
	push(a, b, 'a');
	if ((!dir && a->head->num > a->head->next->num) || (dir && a->head->num < a->head->next->num))
		swap(a, 'a');
}

void	sort_small_case(t_stack *a, t_stack *b, int size, int dir)
{
	int	rotate_num;

	if (size <= 2)
		sort_under_two(a, b, size, dir);
	else if (size == 3)
		sort_three(a, b, dir);
	else
	{
		rotate_num = 2;
		sort_under_two(b, a, 2, !dir);
		if (size == 4)
			sort_under_two(a, b, 2, dir);
		else
		{
			rotate_num = 3;
			sort_three(a ,b, dir);
		}
		while (rotate_num-- > 0)
			rotate(a, 'a');
		small_merge(a, b, size, dir);
	}
}

void	sort_to_a(t_stack *a, t_stack *b, int size, int dir)
{
	int	bottom_size;
	int	top_size;

	if (size <= 5)
	{
		sort_small_case(a, b, size, dir);
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
