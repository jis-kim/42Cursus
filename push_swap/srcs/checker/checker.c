/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:44:21 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 16:02:36 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_cmd	*cmd_h;

	if (argc < 2)
		return (0);
	a = parse(argc, argv);
	b = ft_calloc(1, sizeof(t_stack));
	b->name = 'b';
}
