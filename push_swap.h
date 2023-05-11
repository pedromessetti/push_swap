/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/11 16:24:43 by pmessett         ###   ########.fr       */
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

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/* --- General functions --- */

size_t				ft_strlen(const char *s);
long				ft_atoi(const char *nptr);
int					is_digit(char c);
int					is_numeric(char *s);
int					check_for_dup(long tmp, char **av, int i);

/* --- Operation functions --- */

void				push(t_stack **stack, int value, int i);
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* --- Stack functions --- */

int					stack_size(t_stack **stack);
void				free_stacks(t_stack **stack);
void				print_stack(t_stack **stack);
t_stack				*init_stack(void);
t_stack				*add_node(int value);
t_stack				*find_last(t_stack *stack);
void				add_tail(t_stack **stack_head, t_stack *new_node);

/* --- Sort Functions --- */

int					stack_is_sorted(t_stack *a);
void				sort_stack(t_stack **a, t_stack **b);
int					find_largest(t_stack **stack);
int					find_smallest(t_stack **stack);

/* --- Check functions --- */

void				check_and_push(char **av, t_stack **a);

#endif