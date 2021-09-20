CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard ./*.c)
OBJS	= $(SRCS:.c=.o)
NAME	= a.out
LIB		= ./libft/libft.a

all : $(NAME)

clean :
	rm -f $(NAME); cd libft; make fclean; cd ..;

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) $(SRCS) ./libft/libft.a

$(LIB) :
	cd ./libft ; make re

D_TEST	= a.out.dSYM
DFLAG	= -g3

libft: $(LIB)

$(D_TEST) : $(LIB)
	$(CC) $(CFLAGS) $(DFLAG) $(SRCS) ./libft/libft.a

debug : $(D_TEST)

dclean :
	rm -rf $(D_TEST)

re : clean all
