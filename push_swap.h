/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/03 12:39:44 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
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
int					ft_atoi(const char *nptr);
int					ft_isnumeric(int c);
char				**ft_split(char const *s, char c);

/* --- Operation functions --- */

void				push(t_stack *stack, int value);
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				swap(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

/* --- Stack functions --- */

int					stack_size(t_stack *stack);
void				free_stack(t_stack *stack);
void				print_stack(t_stack *stack);

#endif