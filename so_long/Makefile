# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 17:07:23 by jiskim            #+#    #+#              #
#    Updated: 2021/12/15 21:49:31 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXDIR = ./mlx
LIB = -L$(MLXDIR) -lmlx -framework OpenGl -framework Appkit

SRCS = $(wildcard ./srcs/*.c)
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
	rm -f $(NAME)

debug : $(OBJS)
	$(MLXLIB)
	$(CC) -g3 -fsanitize=address $(LIB) $(SRCS) -o $(NAME)

re : fclean all
