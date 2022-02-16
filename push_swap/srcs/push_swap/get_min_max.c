/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:02:40 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 16:07:12 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
