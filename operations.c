/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:41:58 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/05 18:44:32 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------- Push ---------- */

/* Push a value to the end of the stack */
void	push(t_stack *stack, int value, int i)
{
	t_stack	*new_node;
	t_stack	*current;

	if (!(new_node = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	new_node->value = value;
	new_node->index = i;
	new_node->next = NULL;
	if (!stack->top)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

/* Take the first element at the top of a and put it at the top of b. */
void	pb(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!a->top)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "pb\n", 3);
}

/* Take the first element at the top of b and put it at the top of a. */
void	pa(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (!b->top)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "pa\n", 3);
}

/* ---------- Swap ---------- */

/* Swap the first 2 elements at the top of the stack passes as parameter */
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

/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/* Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/* Swap the first 2 elements at the top of the stack a and b at the same time */
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

/* ---------- Rotate ---------- */

/* Main function for rotate elements of the stack 
The first element becomes the last one */
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

/* Shift up all elements of stack a by 1.
The first element becomes the last one */
void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/*Shift up all elements of stack b by 1.
The first element becomes the last one */
void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/* Execute rotate of the stack a and b at the same time */
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

/* ---------- Reverse Rotate ---------- */

/* Main function for rotate elements of the stack 
The last element becomes the first one */
void	reverse_rotate(t_stack *stack)
{
	t_stack	*to_last;

	if (!stack->top || !stack->top->next)
		return ;
	to_last = stack->top;
	while (to_last->next->next)
		to_last = to_last->next;
	to_last->next->next = stack->top;
	stack->top = to_last->next;
	to_last->next = NULL;
}

/* Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/* Shift down all elements of stack b by 1.
The last element becomes the first one. */
void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/* Execute reverse rotate of the stack a and b at the same time */
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
