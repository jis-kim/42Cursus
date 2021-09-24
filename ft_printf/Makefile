# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 19:52:11 by jiskim            #+#    #+#              #
#    Updated: 2021/09/24 19:52:12 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard ./*.c)
OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a

LIBDIR	= ./libft
LIB		= $(LIBDIR)/libft.a

D_TEST	= a.out.dSYM
DFLAG	= -g3

all : $(NAME)

clean :
	rm -f $(NAME) $(OBJS)
	make -C $(LIBDIR) fclean

$(NAME) : $(LIB) $(OBJS)
	ar rcs $@ $(OBJS)

$(LIB) :
	make -C $(LIBDIR)
	cp $@ $(NAME)

$(D_TEST) : $(LIB)
	$(CC) $(CFLAGS) $(DFLAG) $(LIB) $(SRCS)

debug : $(D_TEST)

dclean :
	rm -rf $(D_TEST)

fclean : clean dclean
	rm -f a.out

bonus : re

re : fclean all

.PHONY: all clean fclean bonus re dclean
