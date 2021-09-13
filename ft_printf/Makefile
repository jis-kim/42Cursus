CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard ./*.c)
OBJS	= $(SRCS:.c=.o)
NAME	= a.out

all : $(NAME)

clean :
	rm -f $(NAME)

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) $(SRCS) ./libft/libft.a

$(LIB) :
	cd ./libft ; make

re : clean all
