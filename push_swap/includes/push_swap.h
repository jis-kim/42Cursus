/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:20:30 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/07 02:47:31 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"

typedef struct s_node
{
	int		num;
	int		index;
	struct	s_node	*next;
}t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}t_stack;

void	print_error();
t_stack	*parse(int argc, char** argv);

#endif
