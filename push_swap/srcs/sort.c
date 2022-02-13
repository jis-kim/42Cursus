/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:26:18 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/12 17:15:07 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief
 * 1. asc a
 *	1) asc b
 *	2) asc a
 *	3) rr
 *	4) desc b
 *	5) merge to a
 *
 * 2. asc b
 *	1) asc b
 *	2) asc a
 *	3) rr
 *	4) desc a
 *	5) merge to b
 *
 * 3. desc a
 *	1) desc b
 *	2) desc a
 *	3) rr
 *	4) asc b
 *	5) merge to a
 *
 * 4. desc b
 *	1) desc b
 *	2) desc a
 *	3) rr
 *	4) asc a
 *	5) merge to b
 *
 * @param offset
 * 	각 영역의 끝 index를
 *
 * @return
 * 	각 영역의 끝 index를 반환한다 (스택의 안쪽)
 */

t_node	*sort_to_a(t_stack *a, t_stack *b, int size, int direction)
{
	int	fst_size;
	int	snd_size;
	int	thd_size;

	if (a->size < 3) // some sorting
		return NULL;
	fst_size = size / 3;
	snd_size = size / 3;
	thd_size = size / 3  + size % 3;
	sort_to_b(a, b , fst_size, direction);
	sort_to_a(a, b , snd_size, direction);
	rr(a, b);
	sort_to_a(a, b, thd_size, !direction);
	merge(a, b, size, direction);
}

t_node	*sort_to_b(t_stack *a, t_stack *b, int size, int direction)
{
	int	fst_size;
	int	snd_size;
	int	thd_size;

	if (a->size < 3) // some sorting
		return NULL;
	fst_size = size / 3;
	snd_size = size / 3;
	thd_size = size / 3  + size % 3;
	sort_to_b(a, b , fst_size, direction);
	sort_to_a(a, b , snd_size, direction);
	rr(a, b);
	sort_to_a(a, b, thd_size, !direction);
	merge(b, a, size, direction);
}
