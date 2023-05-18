.SILENT:
NAME = push_swap.a

CC = cc

CME = ar -rcs

FLAGS = -Wall -Wextra -Werror -g #fsanitize=address

SRCS = $(*.c)

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
	$(CME) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

compile: re
	$(CC) $(FLAGS) *.c -o push_swap

run: compile
	rm -f *.o $(NAME)