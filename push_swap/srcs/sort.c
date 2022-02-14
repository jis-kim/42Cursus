/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:26:18 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/14 21:26:19 by jiskim           ###   ########.fr       */
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

void	sort_three_asc(t_stack *a, t_stack *b)
{
	int	fst;
	int	snd;
	int	thd;
	int	max_value;

	fst = a->head->num;
	snd = a->head->next->num;
	thd = a->head->next->next->num;
	max_value = max(fst, snd, thd);
	if (max_value == 2)
	{
		if (fst > snd)
			swap(a, 'a');
		return ;
	}
	if (max_value == 0)
		swap(a, 'a');
	push(b, a, 'b');
	swap(a, 'a');
	push(a, b, 'a');
	if (a->head->num > a->head->next->num)
		swap(a, 'a');
}

void	sort_three_desc(t_stack *a, t_stack *b)
{
	int	fst;
	int	snd;
	int	thd;
	int	min_value;

	fst = a->head->num;
	snd = a->head->next->num;
	thd = a->head->next->next->num;
	min_value = min(fst, snd, thd);
	if (min_value == 2)
	{
		if (fst < snd)
			swap(a, 'a');
		return ;
	}
	if (min_value == 0)
		swap(a, 'a');
	push(b, a, 'b');
	swap(a, 'a');
	push(a, b, 'a');
	if (a->head->num < a->head->next->num)
		swap(a, 'a');
}

void	sort_small_case(t_stack *a, t_stack *b, int size, int dir)
{
	int	chunk_size[3];

	ft_bzero(chunk_size, 3 * sizeof(int));
	if (size == 3 && dir == asc)
		sort_three_asc(a, b);
	else if (size == 3 && dir == desc)
		sort_three_desc(a, b);
	else if (size <= 2)
		sort_under_two(a, b, size, dir);
	else if (size == 4)
	{
		chunk_size[0] = 2;
		chunk_size[2] = 2;
		sort_under_two(b, a, 2, !dir);
		sort_under_two(a, b, 2, dir);
		rotate(a, 'a');
		rotate(a, 'a');
		small_merge(a, b, chunk_size, dir);
	}
	else
	{
		chunk_size[0] = 3;
		chunk_size[2] = 2;
		sort_under_two(b, a, 2, !dir);
		if (dir == asc)
			sort_three_asc(a, b);
		else
			sort_three_desc(a, b);
		rotate(a, 'a');
		rotate(a, 'a');
		rotate(a, 'a');
		small_merge(a, b, chunk_size, dir);
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
