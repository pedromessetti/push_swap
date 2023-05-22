.SILENT:
# Color variables
RED = \033[1;31m
GREEN = \033[1;32m
WHITE = \033[1;37m
RESET = \033[0m

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I inc

SRCS =	operations/push.c operations/swap.c operations/rotate.c operations/rev_rotate.c \
		utils/stack_utils.c utils/big_sort_utils.c utils/cost_utils.c utils/ft_utils.c utils/sort_utils.c utils/find_utils.c \
		sort/big_sort_aux.c sort/big_sort.c sort/small_sort.c \
		verifications.c \
		main.c

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