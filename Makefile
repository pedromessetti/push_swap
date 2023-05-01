.SILENT:
NAME = push_swap.a

CC = cc

CME = ar -rcs

FLAGS = -Wall -Wextra -Werror

ARGS = "7 -11 12 83 9 2 0 43 -9 -3 5"

SRCS = push_swap.c \
utils.c \
main.c

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
	@$(CME) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:	fclean all

compile: re
	@$(CC) *.c -o push_swap

run: compile
	@rm -f *.o $(NAME)
	@./push_swap $(ARGS)