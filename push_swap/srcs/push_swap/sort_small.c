/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:13:19 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 16:23:33 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three(t_stack *a)
{
	int	max_val;

	if (a->head->num < a->head->next->num && a->head->next->num < a->tail->num)
		return ;
	max_val = max(a->head->num, a->head->next->num, a->tail->num);
	if (0 == max_val)
	{
		rotate(a, 'a');
		if (a->head->num < a->head->next->num)
			return ;
	}
	else if (1 == max_val)
	{
		reverse_rotate(a, 'a');
		if (a->head->num < a->head->next->num)
			return ;
	}
	swap(a, 'a');
}

void	sort_small(t_stack *a, t_stack *b, int size)
{
	if (size <= 2)
		sort_under_two(a, b, size, asc);
	else if (size == 3)
		sort_three(a);
	else
	{
		sort_under_two(b, a, 2, desc);
		if (size == 4)
			sort_under_two(a, b, 2, asc);
		else
			sort_three(a);
		small_merge(a, b, size, asc);
	}
}

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

void	sort_three_chunk(t_stack *a, t_stack *b, int dir)
{
	int	nums[3];
	int	min_or_max;

	nums[0] = a->head->num;
	nums[1] = a->head->next->num;
	nums[2] = a->head->next->next->num;
	if (dir == asc)
		min_or_max = max(nums[0], nums[1], nums[2]);
	else
		min_or_max = min(nums[0], nums[1], nums[2]);
	if (min_or_max == 2)
	{
		if ((!dir && nums[0] > nums[1]) || (dir && nums[0] < nums[1]))
			swap(a, 'a');
		return ;
	}
	if (min_or_max == 0)
		swap(a, 'a');
	push(b, a, 'b');
	swap(a, 'a');
	push(a, b, 'a');
	if ((!dir && a->head->num > a->head->next->num)
		|| (dir && a->head->num < a->head->next->num))
		swap(a, 'a');
}

void	sort_small_chunk(t_stack *a, t_stack *b, int size, int dir)
{
	int	rotate_num;

	if (size <= 2)
		sort_under_two(a, b, size, dir);
	else if (size == 3)
		sort_three_chunk(a, b, dir);
	else
	{
		rotate_num = 2;
		sort_under_two(b, a, 2, !dir);
		if (size == 4)
			sort_under_two(a, b, 2, dir);
		else
		{
			rotate_num = 3;
			sort_three_chunk(a, b, dir);
		}
		while (rotate_num-- > 0)
			rotate(a, 'a');
		small_merge(a, b, size, dir);
	}
}
