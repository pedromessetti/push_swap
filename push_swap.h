/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/17 23:44:54 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

//# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct du_cost
{
	int				bf;
	int				val;
	int				cost;
	struct du_cost	*next;
}					du_cost;

/* --- General functions --- */

size_t				ft_strlen(const char *s);
long				ft_atoi(const char *nptr);
int					is_digit(char c);
int					is_numeric(char *s);
int					check_for_dup(long tmp, char **av, int i);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memset(void *s, int c, size_t n);

/* --- Operation functions --- */

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
t_stack				*add_number_to_stack(int value);
t_stack				*find_last_stack(t_stack *stack);
void				add_tail_to_stack(t_stack **stack_head, t_stack *new_node);
int					find_pos_on_stack(t_stack **stack, int value_to_find);

/* Cost Functions */

du_cost				*add_cost(int val, int bf, int cost);
void				add_tail_to_cost_table(du_cost **stack_head,
						du_cost *new_node);
du_cost				*find_last_cost(du_cost *cost_table);

/* --- Sort Functions --- */

int					stack_is_sorted(t_stack **stack);
void				sort_stack(t_stack **a, t_stack **b);
int					find_largest(t_stack **stack);
int					find_smallest(t_stack **stack);
void				define_sort(t_stack **a, t_stack **b);
void				sort_stack_of_2(t_stack **a);
void				sort_stack_of_3(t_stack **a);
void				sort_stack_of_5(t_stack **a, t_stack **b, int option);
void				sort_stack_of_5__aux(t_stack **a, t_stack **b);
void				sort_stack_of_5__aux_option(t_stack **a, t_stack **b);
void				sort_stack_of_100(t_stack **a, t_stack **b);

/* --- Check functions --- */

void				check_and_push(char **av, t_stack **a);

/* X functions */

int					sum_val(t_stack **a);
int					find_max_value(t_stack **stack, int size);
int					find_bf(t_stack **a, int value);
int					calc_cost(int num, int bf, t_stack **a, t_stack **b);
void				move_bf_to_top(int val, t_stack **a);
void				move_num_to_top(int val, t_stack **b);
void				auxiliar_1(t_stack **a, t_stack **b);

#endif