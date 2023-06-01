.SILENT:
# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I inc #-fsanitize=address

SRCS =	src/operations/push.c src/operations/swap.c src/operations/rotate.c src/operations/rev_rotate.c \
		src/stack_utils.c src/big_sort_utils.c src/cost_utils.c src/ft_utils.c src/small_sort_utils.c src/stack_utils2.c \
		src/big_sort_utils2.c src/big_sort.c src/small_sort.c src/checks.c src/main.c

OBJS = $(SRCS:.c=.o)

CHAR = =-=
NUM = 7
REPEATED_CHARS = $(call repeat_char,$(shell seq $(NUM)))

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(WHITE)     $(NAME)"| tr '[:lower:]' '[:upper:]'
	echo "$(GREEN)$(REPEATED_CHARS)$(RESET)" 
	echo "$(GREEN)SUCCESSFULLY COMPILED$(RESET)"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

run: re
	$(MAKE) clean

define repeat_char
$(strip $(if $(firstword $(1)), $(CHAR)$(call repeat_char,$(subst $(firstword $(1)),,$(1)))))
endef