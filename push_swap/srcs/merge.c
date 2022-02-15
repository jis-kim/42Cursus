/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:44:59 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 21:02:27 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_chunk(t_stack *dst, t_stack *other, int chunk_size[])
{
	int	result;

	result = 0;
	if (chunk_size[0] > 0)
	{
		if (chunk_size[1] > 0 && chunk_size[2] > 0)
			result = max(dst->tail->num, other->tail->num, other->head->num);
		else if (chunk_size[1] > 0 && (dst->tail->num < other->tail->num))
			result = 1;
		else if (chunk_size[2] > 0 && (dst->tail->num < other->head->num))
			result = 2;
	}
	else
	{
		if (chunk_size[1] > 0)
		{
			result = 1;
			if (chunk_size[2] > 0 && (other->tail->num < other->head->num))
				result = 2;
		}
		else
			result = 2;
	}
	return (result);
}

int	get_min_chunk(t_stack *dst, t_stack *other, int chunk_size[])
{
	int	result;

	result = 0;
	if (chunk_size[0] > 0)
	{
		if (chunk_size[1] > 0 && chunk_size[2] > 0)
			result = min(dst->tail->num, other->tail->num, other->head->num);
		else if (chunk_size[1] > 0 && (dst->tail->num > other->tail->num))
			result = 1;
		else if (chunk_size[2] > 0 && (dst->tail->num > other->head->num))
			result = 2;
	}
	else
	{
		if (chunk_size[1] > 0)
		{
			result = 1;
			if (chunk_size[2] > 0 && (other->tail->num > other->head->num))
				result = 2;
		}
		else
			result = 2;
	}
	return (result);
}

void	small_merge(t_stack *dst, t_stack *other, int size, int dir)
{
	int	selected_chunk;
	int	chunk_size[3];

	chunk_size[0] = size / 2 + size % 2;
	chunk_size[1] = 0;
	chunk_size[2] = size / 2;
	while (chunk_size[0] + chunk_size[1] + chunk_size[2] > 0)
	{
		if (dir == asc)
			selected_chunk = get_max_chunk(dst, other, chunk_size);
		else
			selected_chunk = get_min_chunk(dst, other, chunk_size);
		if (selected_chunk == 0)
			reverse_rotate(dst, dst->name);
		else if (selected_chunk == 1)
			reverse_rotate(other, other->name);
		if (selected_chunk > 0)
			push(dst, other, dst->name);
		chunk_size[selected_chunk]--;
	}
}

void	merge(t_stack *dst, t_stack *other, int size, int dir)
{
	int	chunk_size[3];
	int	selected_chunk;

	chunk_size[0] = size / 3;
	chunk_size[2] = size / 3;
	if (size % 3 == 2)
		chunk_size[0]++;
	if (size % 3 == 1)
		chunk_size[2]++;
	chunk_size[1] = chunk_size[0];
	while (chunk_size[0] + chunk_size[1] + chunk_size[2] > 0)
	{
		if (dir == asc)
			selected_chunk = get_max_chunk(dst, other, chunk_size);
		else
			selected_chunk = get_min_chunk(dst, other, chunk_size);
		if (selected_chunk == 0)
			reverse_rotate(dst, dst->name);
		else if (selected_chunk == 1)
			reverse_rotate(other, other->name);
		if (selected_chunk > 0)
			push(dst, other, dst->name);
		chunk_size[selected_chunk]--;
	}
}
