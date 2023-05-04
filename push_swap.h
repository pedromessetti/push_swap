/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/04 11:19:45 by pmessett         ###   ########.fr       */
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
	int				value;
	struct s_stack	*top;
	struct s_stack	*next;
}					t_stack;

/* --- General functions --- */

size_t				ft_strlen(const char *s);
long int			ft_atoi(const char *nptr);
int					ft_isdigit(int c);
int					ft_isnumeric(char *s);
char				**ft_split(char const *s, char c);
int					check_for_dup(long int tmp, char **av, int i);

/* --- Operation functions --- */

void				push(t_stack *stack, int value);
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				swap(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

/* --- Stack functions --- */

int					stack_size(t_stack *stack);
void				free_stacks(t_stack *a, t_stack *b);
void				print_stack(t_stack *stack);

#endif