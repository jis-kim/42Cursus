/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:33 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/13 16:34:24 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_chunk(t_stack *dst, t_stack *other)
{
	int	fst;
	int	snd;
	int	thd;

	if (dst->size)
	fst = dst->tail->num;
	snd = other->head->num;
	thd = other->tail->num;

	if (fst > snd)
		if (fst > thd)
			return (1);
	else
		if (snd > thd)
			return (2);
	return (3);
}
