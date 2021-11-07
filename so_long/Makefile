# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 17:07:23 by jiskim            #+#    #+#              #
#    Updated: 2021/11/07 01:57:29 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L./mlx -lmlx -framework OpenGl -framework Appkit

SRCS = a.c
OBJS = $(SRCS:.c=.o)

NAME = so_long

all : $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(SRCS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
