CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard ./*.c)
OBJS	= $(SRCS:.c=.o)
NAME	= a.out

all : $(NAME)
	
clean :
	rm -f $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) $(SRCS)