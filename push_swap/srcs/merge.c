/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:44:59 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/13 22:33:43 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max(int a, int b, int c)
{
	if (a > b && a > c)
		return (0);
	if (b > c)
		return (1);
	return (2);
}

int	min(int a, int b, int c)
{
	if (a < b && a < c)
			return (0);
	if (b < c)
			return (1);
	return (2);
}

int	get_max_chunk(t_stack *dst, t_stack *other, int chunk_size[])
{
	int	result;

	result = 0;
	if (chunk_size[0] > 0) //0 있음
	{
		if (chunk_size[1] > 0 && chunk_size[2] > 0) // 셋 다 있음
			result = max(dst->tail->num, other->tail->num, other->head->num);
		else if (chunk_size[1] > 0 && (dst->tail->num < other->tail->num)) //0과 1이 있음 근데 1이 큼
			result = 1;
		else if (chunk_size[2] > 0 && (dst->tail->num < other->head->num)) //0과 2가 있음.. 근데 2가 큼
			result = 2;
	}
	else //0 없음 -> 0일 일 없어^^
	{
		if (chunk_size[1] > 0)
		{
			result = 1;
			if (chunk_size[2] > 0 && (other->tail->num < other->head->num)) //1도 2도 있는데 2가 더 큼
				result = 2;
		}
		else // 0도 없고 1도 없음;
			result = 2;
	}
	return (result);
}

int	get_min_chunk(t_stack *dst, t_stack *other, int chunk_size[])
{
	int	result;

	result = 0;
	if (chunk_size[0] > 0) //0 있음
	{
		if (chunk_size[1] > 0 && chunk_size[2] > 0) // 셋 다 있음
			result = min(dst->tail->num, other->tail->num, other->head->num);
		else if (chunk_size[1] > 0 && (dst->tail->num > other->tail->num)) //0과 1이 있음 근데 1이 작음
			result = 1;
		else if (chunk_size[2] > 0 && (dst->tail->num > other->head->num)) //0과 2가 있음.. 근데 2가 작음
			result = 2;
	}
	else //0 없음 -> 0일 일 없어^^
	{
		if (chunk_size[1] > 0)
		{
			result = 1;
			if (chunk_size[2] > 0 && (other->tail->num > other->head->num)) //1도 2도 있는데 2가 더 작음
				result = 2;
		}
		else // 0도 없고 1도 없음;
			result = 2;
	}
	return (result);
}

/**
 * @brief
 * a라면 b바닥 (rb pa)
 * a바닥 (ra)
 * b천장 (pa) 순
 *
 * b라면 b바닥 (rb)
 * a바닥 (ra pb)
 * a천장 (pb) 순
 *
 * @param dst
 * @param other
 * @param size
 * @param direction
 */
void	merge(t_stack *dst, t_stack *other, int size, int direction)
{
	int	chunk_size[3];
	int	selected_chunk;

	chunk_size[0] = size / 3;
	chunk_size[1]  = size / 3;
	chunk_size[2]  = size / 3  + size % 3;
	while (chunk_size[0] + chunk_size[1] + chunk_size[2] > 0)
	{
		if (direction == asc)
			selected_chunk = get_max_chunk(dst, other, chunk_size);
		else
			selected_chunk = get_min_chunk(dst, other, chunk_size);
		if (selected_chunk == 0)
			reverse_rotate(dst, dst->name);
		else if (selected_chunk == 1)
		{
			reverse_rotate(other, other->name);
			push(dst, other, dst->name);
		}
		else
			push(dst, other, dst->name);
		chunk_size[selected_chunk]--;
	}
}
