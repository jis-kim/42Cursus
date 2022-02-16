/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:55:03 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 16:27:20 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H
# define INT_MAX 2147483647

# include "../srcs/get_next_line/get_next_line.h"

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
t_stack	*parse(int argc, char **argv);

#endif
