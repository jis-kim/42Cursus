# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 17:07:23 by jiskim            #+#    #+#              #
#    Updated: 2022/01/04 02:37:16 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXDIR = ./mlx
SRCSDIR = ./srcs/
GNLDIR = $(SRCSDIR)/get_next_line/
LIB = -L$(MLXDIR) -lmlx -framework OpenGl -framework Appkit

SRCS = $(addprefix $(SRCSDIR), check_file.c handle_error.c initialize.c \
key_event.c main.c parse_map.c utils.c check_map_format.c show_map.c) \
$(addprefix $(GNLDIR), get_next_line_utils.c get_next_line.c)
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
