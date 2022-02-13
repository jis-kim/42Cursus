/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:44:59 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/13 16:39:32 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief
 *
 * @param dst
 * @param other
 * @param chunk_size
 * @return int
 * first -> 1, second -> 2, third -> 3
 */
int	max_merge(t_stack *dst, t_stack *other, int chunk_size[])
{
	int	fst; //dst tail
	int	snd; //other head
	int	thd; //other tail

	if (chunk_size[0] <= 0)
	{

	}

	if (chunk_size[0] > 0 && chunk_size[1] > 0 && chunk_size[2] > 0)
	{
		fst = dst->tail->num;
		snd = other->head->num;
		thd = other->tail->num;
	}

	if (fst > snd && fst > thd)
		rotate(dst);
	else if (snd > thd)
		push(dst, other);
	else
	{
		rotate(other);
		push(dst, other);
	}
}
/**
 * @brief first가 크면 r_dst
 * second가 크면 p_dst
 * third가 크면 r_other p_dst
 */
void	merge(t_stack *dst, t_stack *other, int size, int direction)
{
	int	chunk_size[3];

	chunk_size[0] = size / 3;
	chunk_size[1]  = size / 3;
	chunk_size[2]  = size / 3  + size % 3;

	while (chunk_size[0] + chunk_size[1] + chunk_size[2]  > 0)
	{
		if (direction == asc)
			chunk_size[max_merge(dst, other, chunk_size)]--;
		else
			chunk_size[min_merge(dst, other, chunk_size)]--;
	}
}
