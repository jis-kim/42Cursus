# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 17:52:40 by jiskim            #+#    #+#              #
#    Updated: 2022/02/16 16:47:08 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
BONDIR	=	./bonus/
SRCSDIR	=	./srcs/
INCDIR	=	./includes/
LIBDIR	=	$(SRCSDIR)libft/
PSDIR	=	$(SRCSDIR)push_swap/
CKDIR	=	$(SRCSDIR)checker/

SRCS	=	$(addprefix $(PSDIR), cmd_ops.c get_min_max.c merge.c parse.c \
			print.c push_swap.c push_swap_ops.c rotate_ops.c \
			sort.c sort_small.c)
OBJS	=	$(SRCS:.c=.o)
SRCS_B	=	$(addprefix $(BONDIR), $(wildcard *.c))
OBJS_B	=	$(SRCS_B:.c=.o)
NAME	=	push_swap
LIB		=	$(LIBDIR)libft.a

D_TEST	=	a.out
DFLAG	=	-g3

all	: $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@

$(LIB) :
	make -C $(LIBDIR)

clean :
	rm -f $(NAME) $(OBJS) $(OBJS_B)
	make -C $(LIBDIR) fclean

$(D_TEST) : $(LIB)
	$(CC) $(CFLAGS) $(DFLAG) $(SRCS) $(LIB)

debug : $(D_TEST)

address : $(LIB)
	$(CC) $(CFLAGS) $(DFLAG) -fsanitize=address $(SRCS) $(LIB)

dclean :
	rm -rf $(D_TEST) a.out.dSYM

fclean : clean dclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re dclean
