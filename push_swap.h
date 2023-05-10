/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/10 22:53:46 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define DECIMAL 0123456789
# define BINARY 01

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_node
{
	int					value;
	int					index;
	struct stack_node	*next;
}						stack_node;

typedef struct stack_head
{
	struct stack_node	*head;
}						stack_head;

/* --- General functions --- */

size_t					ft_strlen(const char *s);
long					ft_atoi(const char *nptr);
int						is_digit(char c);
int						is_numeric(char *s);
int						check_for_dup(long tmp, char **av, int i);

/* --- Operation functions --- */

void					push(stack_head *stack, int value, int i);
void					pb(stack_head *a, stack_head *b);
void					pa(stack_head *a, stack_head *b);
void					swap(stack_head *stack);
void					sa(stack_head *a);
void					sb(stack_head *b);
void					ss(stack_head *a, stack_head *b);
void					rotate(stack_head *stack);
void					ra(stack_head *a);
void					rb(stack_head *b);
void					rr(stack_head *a, stack_head *b);
void					reverse_rotate(stack_head *stack);
void					rra(stack_head *a);
void					rrb(stack_head *b);
void					rrr(stack_head *a, stack_head *b);

/* --- Stack functions --- */

int						stack_size(stack_head *stack);
void					free_stacks(stack_head *a, stack_head *b);
void					print_stack(stack_head *stack);
stack_head				*init_stack(stack_head *stack);

/* --- Sort Functions --- */

int						stack_is_sorted(stack_head *a);
void					sort_stack(stack_head *a, stack_head *b, int ac);
int						find_largest(stack_head *stack);
int						find_smallest(stack_head *stack);

/* --- Check functions --- */

void					check_and_push(char **av, stack_head *a, stack_head *b);

#endif