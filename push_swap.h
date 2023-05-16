/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/15 15:12:24 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define CHUNK1 012345678910111213141516171819
# define CHUNK2 2021222324252627282930313233343536373839
# define CHUNK3 4041424344454647484950515253545556575859
# define CHUNK4 6061626364656667686970717273747576777879
# define CHUNK5 8081828384858687888990919293949596979899

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/* --- General functions --- */

size_t				ft_strlen(const char *s);
long				ft_atoi(const char *nptr);
int					is_digit(char c);
int					is_numeric(char *s);
int					check_for_dup(long tmp, char **av, int i);

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
t_stack				*add_node(int value);
t_stack				*find_last(t_stack *stack);
void				add_tail(t_stack **stack_head, t_stack *new_node);
int					find_pos_on_stack(t_stack **stack, int value_to_find);

/* --- Sort Functions --- */

int					stack_is_sorted(t_stack **stack);
void				sort_stack(t_stack **a, t_stack **b);
int					find_largest(t_stack **stack);
int					find_smallest(t_stack **stack);
void				define_sort(t_stack **a, t_stack **b);
void				sort_stack_of_2(t_stack **a);
void				sort_stack_of_3(t_stack **a);
void				rra_for_(t_stack **a, int value);
void				ra_for_(t_stack **a, int value);
void				insertion_sort(t_stack **a, t_stack **b);

/* --- Check functions --- */

void				check_and_push(char **av, t_stack **a);

#endif