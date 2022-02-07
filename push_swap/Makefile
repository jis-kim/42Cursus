# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 17:52:40 by jiskim            #+#    #+#              #
#    Updated: 2022/02/07 18:14:36 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
BONDIR	=	./bonus/
SRCSDIR	=	./srcs/
LIBDIR	=	$(SRCSDIR)libft/
SRCS	=	$(addprefix $(SRCSDIR), parse.c print_error.c push_swap.c stack_operation.c)
OBJS	=	$(SRCS:.c=.o)
SRCS_B	=	$(addprefix $(BONDIR), $(wildcard *.c))
OBJS_B	=	$(SRCS_B:.c=.o)
NAME	=	push_swap
LIB		=	$(LIBDIR)libft.a

D_TEST	=	a.out.dSYM
DFLAG	=	-g3 -fsanitize=address

#ifdef SRCS_B_RELINK
#	OBJS_FILES = $(OBJS_B)
#else
#	OBJS_FILES = $(OBJS)


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

$(D_TEST) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(DFLAG) $(OBJS) $(LIB)

debug : $(D_TEST)

dclean :
	rm -rf $(D_TEST)

fclean : clean dclean
	rm -f $(NAME)

bonus :
	make SRCS_B_RELINK=1 all

re : fclean all

.PHONY: all clean fclean bonus re dclean
