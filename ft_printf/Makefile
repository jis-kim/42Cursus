# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 19:52:11 by jiskim            #+#    #+#              #
#    Updated: 2021/09/25 16:28:49 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	calc_mac.c ft_print_char.c ft_print_dec.c ft_print_hex.c\
			ft_print_options.c ft_printf.c parse_format.c
OBJS	=	$(SRCS:.c=.o)
SRCS_B	=	$(addprefix $(BONDIR)/, SRCS)
OBJS_B	=	$(SRCS_B:.c=.o)
NAME	=	libftprintf.a
BONDIR	=	./bonus

LIBDIR	=	./libft
LIB		=	$(LIBDIR)/libft.a

D_TEST	=	a.out.dSYM
DFLAG	=	-g3

ifdef SRCS_B_RELINK
	OBJS_FILES = $(OBJS_B)
else
	OBJS_FILES = $(OBJS)
endif

all	: $(NAME)

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
	rm -f $(NAME)

bonus :
	make SRCS_B_RELINK=1 all

re : fclean all

.PHONY: all clean fclean bonus re dclean
