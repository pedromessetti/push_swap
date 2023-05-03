/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:41:58 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/03 12:38:40 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --- Push Functions ---*/

void	push(t_stack *stack, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

void	pb(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!a->top)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;
}

void	pa(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!b->top)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;
}

/* --- Swap Functions --- */

void	swap(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

/* --- Rotate Functions --- */

void	rotate(t_stack *stack)
{
	t_stack	*last;

	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = stack->top;
	stack->top = stack->top->next;
	last->next->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;

	t_stack *to_last = stack->top;
	while (to_last->next->next)
		to_last = to_last->next;
	to_last->next->next = stack->top;
	stack->top = to_last->next;

	to_last->next = NULL;
}