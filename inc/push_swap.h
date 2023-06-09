/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/01 15:49:15 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/* --- Dependencies Libs --- */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* --- Linked list structures --- */

typedef struct s_stack
{
	int					val;
	struct s_stack		*next;
}						t_stack;

typedef struct s_cost_tab
{
	int					val;
	int					bf;
	int					cost;
	struct s_cost_tab	*next;
}						t_cost_tab;

/* --- General functions --- */

size_t					ft_strlen(const char *s);
long					ft_atoi(const char *nptr);
int						ft_is_digit(char c);
int						ft_str_is_num(char *s);

/* --- Movement functions --- */

void					pb(t_stack **a, t_stack **b);
void					pa(t_stack **a, t_stack **b);

void					swap(t_stack **stack);
void					sa(t_stack **a);
void					sb(t_stack **b);
void					ss(t_stack **a, t_stack **b);

void					rotate(t_stack **stack);
void					ra(t_stack **a);
void					rb(t_stack **b);
void					rr(t_stack **a, t_stack **b);

void					reverse_rotate(t_stack **stack);
void					rra(t_stack **a);
void					rrb(t_stack **b);
void					rrr(t_stack **a, t_stack **b);

/* --- Stack functions --- */

t_stack					*add_number_to_stack(int val);
t_stack					*find_tail(t_stack *stack);
void					add_tail_to_stack(t_stack **stack_head,
							t_stack *new_node);
int						find_pos_on_stack(t_stack **stack, int val_to_find);
int						stack_size(t_stack **stack);
void					free_stack(t_stack **stack);
int						find_largest(t_stack **stack);
int						find_smallest(t_stack **stack);

/* --- Cost Functions --- */

t_cost_tab				*add_cost(int val, int bf, int cost);
t_cost_tab				*find_last_cost(t_cost_tab *cost_table);
void	add_tail_to_cost_table(t_cost_tab **table_head,
							t_cost_tab *new_node);
void					free_cost_tab(t_cost_tab **cost_tab);

/* --- Sort Functions --- */

void					sort_stack_of_2(t_stack **a);
void					sort_stack_of_3(t_stack **a);
void					sort_stack_of_5(t_stack **a, t_stack **b);
void					sort_big_stack(t_stack **a, t_stack **b);

/* --- Verification functions --- */

void					check_and_push(char **av, t_stack **a);
int						check_for_dup(long tmp, char **av, int i);
void					define_sort(t_stack **a, t_stack **b);
int						stack_is_sorted(t_stack **stack);

/* --- Auxiliar functions --- */

int						sum_val(t_stack **a);
int						find_bf(t_stack **a, int val);
int						calc_cost(int num, int bf, t_stack **a, t_stack **b);
void					move_bf_to_top(int val, t_stack **a);
void					move_num_to_top(int val, t_stack **b);
void					exec_initial_moves(t_stack **a, t_stack **b);
void					set_cost_table(t_stack **a, t_stack **b,
							t_cost_tab **table);
int						get_best_cost_posix(t_cost_tab **table);
void					exec_rotate_1(t_stack **a, int rotate_count, int size,
							int count_largest);
void					exec_rotate_2(t_stack **a, int rotate_count, int size,
							int count_largest);

#endif
