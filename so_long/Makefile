# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 17:07:23 by jiskim            #+#    #+#              #
#    Updated: 2021/12/31 00:25:38 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
MLXDIR = ./mlx
LIB = -L$(MLXDIR) -lmlx -framework OpenGl -framework Appkit

SRCS = $(wildcard ./srcs/*.c)  $(wildcard ./srcs/get_next_line/*.c)
OBJS = $(SRCS:.c=.o)

NAME = so_long
MLXLIB = make -C $(MLXDIR)

all : $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME) : $(OBJS)
	$(MLXLIB)
	$(CC) $(CFLAGS) $(LIB) $(SRCS) -o $(NAME)

clean :
	make clean -C $(MLXDIR)
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME) so_long.dSYM

debug : fclean $(OBJS)
	$(MLXLIB)
	$(CC) -g3 -fsanitize=address $(LIB) $(SRCS) -o $(NAME)

re : fclean all