/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:20:30 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 16:47:59 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
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

enum e_dir {
	asc = 0,
	desc = 1
};

void	print_error(void);
void	print_command(t_cmd *cmd_h);

t_stack	*parse(int argc, char **argv);

void	swap(t_stack *stack, char name);
void	ss(t_stack *a, t_stack *b);
void	push(t_stack *dst, t_stack *other, char name);
void	rotate(t_stack *stack, char name);
void	reverse_rotate(t_stack *stack, char name);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	sort_to_a(t_stack *a, t_stack *b, int size, int dir);
void	sort_to_b(t_stack *a, t_stack *b, int size, int dir);

void	merge(t_stack *dst, t_stack *other, int size, int dir);

int		max(int a, int b, int c);
int		min(int a, int b, int c);
void	small_merge(t_stack *dst, t_stack *other, int size, int dir);
void	ft_cmd_add(t_cmd **head, char *str);
void	sort_under_two(t_stack *dst, t_stack *other, int size, int dir);
void	sort_small(t_stack *a, t_stack *b, int size);
void	sort_small_chunk(t_stack *a, t_stack *b, int size, int dir);

#endif
