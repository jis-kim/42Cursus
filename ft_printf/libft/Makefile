# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 11:34:13 by jiskim            #+#    #+#              #
#    Updated: 2021/09/22 18:40:11 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	=	ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_strlen.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_atoi.c ft_calloc.c ft_putendl_fd.c
SRCS_B	=	ft_lstadd_back.c ft_lstadd_front.c  ft_lstdelone.c ft_lstmap.c \
			ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstiter.c
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
NAME	= libft.a

ifdef SRCS_B_RELINK
	OBJS_FILES = $(OBJS) $(OBJS_B)
else
	OBJS_FILES = $(OBJS)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS_FILES)
	ar rcs $@ $(OBJS_FILES)

bonus :
	make SRCS_B_RELINK=1 all

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all bonus
