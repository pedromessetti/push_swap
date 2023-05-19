/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/19 05:48:06 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef struct cost_tab
{
	int				bf;
	int				val;
	int				cost;
	struct cost_tab	*next;
}					cost_tab;

/* --- General functions --- */

size_t				ft_strlen(const char *s);
long				ft_atoi(const char *nptr);
int					is_digit(char c);
int					is_numeric(char *s);

/* --- Movement functions --- */

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

void				print_stack(t_stack **stack);
t_stack				*add_number_to_stack(int val);
t_stack				*find_last_stack(t_stack *stack);
void				add_tail_to_stack(t_stack **stack_head, t_stack *new_node);
int					find_pos_on_stack(t_stack **stack, int val_to_find);
int					stack_size(t_stack **stack);
void				free_stack(t_stack **stack);

/* Cost Functions */

void				print_cost(cost_tab **cost_tab);
cost_tab			*add_cost(int val, int bf, int cost);
cost_tab			*find_last_cost(cost_tab *cost_table);
void	add_tail_to_cost_table(cost_tab **table_head,
							cost_tab *new_node);
void				free_cost_tab(cost_tab **cost_tab);

/* --- Sort Functions --- */

void				sort_stack_of_2(t_stack **a);
void				sort_stack_of_3(t_stack **a);
void				sort_stack_of_5(t_stack **a, t_stack **b, int option);
void				sort_stack_of_5__aux(t_stack **a, t_stack **b);
void				sort_stack_of_5__aux_option(t_stack **a, t_stack **b);
void				sort_big_stack(t_stack **a, t_stack **b);

/* --- Verification functions --- */

void				check_and_push(char **av, t_stack **a);
int					check_for_dup(long tmp, char **av, int i);
void				define_sort(t_stack **a, t_stack **b);
int					stack_is_sorted(t_stack **stack);

/* Auxiliar functions */

int					find_largest(t_stack **stack);
int					find_smallest(t_stack **stack);
int					sum_val(t_stack **a);
int					find_bf(t_stack **a, int val);
int					calc_cost(int num, int bf, t_stack **a, t_stack **b);
void				move_bf_to_top(int val, t_stack **a);
void				move_num_to_top(int val, t_stack **b);
void				exec_initial_moves(t_stack **a, t_stack **b);
void				set_cost_table(t_stack **a, t_stack **b, cost_tab **table);
int					get_best_cost_posix(cost_tab **table);
void				exec_rotate(t_stack **a, int rotate_count, int size,
						int count_largest, int option);

#endif
