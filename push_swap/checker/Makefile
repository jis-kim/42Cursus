# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 15:48:53 by jiskim            #+#    #+#              #
#    Updated: 2022/02/16 15:57:58 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
PSDIR	=	../push_swap/srcs/
SRCSDIR	=	./srcs/
GNLDIR	=	$(SRCSDIR)/get_next_line/
LIBDIR	=	$(PSDIR)libft/
SRCS	=	$(addprefix $(SRCSDIR), parse.c print.c \
			push_swap_ops.c rotate_ops.c cmd_ops.c get_min_max.c)
			$(addprefix $(GNLDIR), get_next_line.c get_next_line_utils.c)
OBJS	=	$(SRCS:.c=.o)
SRCS_B	=	$(addprefix $(BONDIR), $(wildcard *.c))
OBJS_B	=	$(SRCS_B:.c=.o)
NAME	=	checker
LIB		=	$(LIBDIR)libft.a

all	: $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@

$(LIB) :
	make -C $(LIBDIR)

clean :
	rm -f $(NAME) $(OBJS) $(OBJS_B)
	make -C $(LIBDIR) fclean

fclean : clean dclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
