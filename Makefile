.SILENT:
NAME = push_swap.a

CC = cc

CME = ar -rcs

FLAGS = -Wall -Wextra -Werror

ARGS = "8 5 6 3 1 2"

SRCS = ft_utils.c \
ft_swap.c \
ft_push.c \
push_swap_utils.c \
lst_utils.c \
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