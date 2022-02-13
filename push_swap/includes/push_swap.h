/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:20:30 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/13 16:39:40 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}t_stack;

enum e_direction {
	asc = 0,
	desc = 1
};

void	print_error(void);
t_stack	*parse(int argc, char** argv);

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif
