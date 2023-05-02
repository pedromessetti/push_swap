/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:34:20 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/02 15:21:09 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_node
{
	int					value;
	int					index;
	struct stack_node	*top;
	struct stack_node	*prev;
	struct stack_node	*next;
}						stack_node;

/* --- General functions --- */
size_t					ft_strlen(const char *s);
int						ft_atoi(const char *nptr);
int						ft_isdigit(int c);
char					**ft_split(char const *s, char c);

/* --- Push Swap functions --- */
void					ft_swap(stack_node *stack);
void					push(stack_node *stack, int value);
void					printStack(stack_node *stack);
void					pb(stack_node *a, stack_node *b);
void					pa(stack_node *a, stack_node *b);

/* --- List functions --- */
int						ft_lstsize(stack_node *lst);

#endif