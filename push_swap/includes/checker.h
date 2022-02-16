/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:55:03 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 18:19:39 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H
# define INT_MAX 2147483647

# include "../srcs/libft/includes/libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}t_node;

typedef struct s_cmd
{
	char			*str;
	struct s_cmd	*next;
}t_cmd;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
	char	name;
	t_cmd	*cmd_h;
}t_stack;

void	print_error(void);
void	insert_stack(t_stack *a, int argc, char **argv);

void	swap(t_stack *stack, char name);
void	ss(t_stack *a, t_stack *b);
void	push(t_stack *dst, t_stack *other, char name);
void	rotate(t_stack *stack, char name);
void	reverse_rotate(t_stack *stack, char name);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
