# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 11:34:13 by jiskim            #+#    #+#              #
#    Updated: 2021/09/25 14:11:17 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	=	ft_atoi.c ft_bzero.c ft_isdigit.c ft_memset.c ft_strchr.c \
			ft_strlen.c ft_putstr.c
OBJS	= $(SRCS:.c=.o)
NAME	= libft.a

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
