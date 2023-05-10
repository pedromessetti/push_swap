/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:41:58 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/10 20:12:12 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------- Push ---------- */

/* Push a value to the end of the stack */
void	push(stack_head *stack, int value, int i)
{
	stack_node	*new_node;
	stack_node	*current;

	new_node = (stack_node *)malloc(sizeof(stack_node));
	if (!new_node)
		exit(1);
	new_node->value = value;
	new_node->index = i;
	new_node->next = NULL;
	if (!stack->head)
		stack->head = new_node;
	else
	{
		current = stack->head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

/* Take the first element at the top of a and put it at the top of b. */
void	pb(stack_head *a, stack_head *b)
{
	stack_node	*node;

	if (!a->head)
		return ;
	node = a->head;
	a->head = a->head->next;
	node->next = b->head;
	b->head = node;
	write(1, "pb\n", 3);
}

/* Take the first element at the top of b and put it at the top of a. */
void	pa(stack_head *a, stack_head *b)
{
	stack_node	*node;

	if (!b->head)
		return ;
	node = b->head;
	b->head = b->head->next;
	node->next = a->head;
	a->head = node;
	write(1, "pa\n", 3);
}

/* ---------- Swap ---------- */

/* Swap the first 2 elements at the top of the stack passes as parameter */
void	swap(stack_head *stack)
{
	stack_node	*first;
	stack_node	*second;
	int			tmp;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = stack->head->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	sa(stack_head *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/* Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void	sb(stack_head *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/* Swap the first 2 elements at the top of the stack a and b at the same time */
void	ss(stack_head *a, stack_head *b)
{
	sa(a);
	sb(b);
}

/* ---------- Rotate ---------- */

/* Main function for rotate elements of the stack 
The first element becomes the last one */
void	rotate(stack_head *stack)
{
	stack_node	*last;

	if (!stack->head || !stack->head->next)
		return ;
	last = stack->head;
	while (last->next)
		last = last->next;
	last->next = stack->head;
	stack->head = stack->head->next;
	last->next->next = NULL;
}

/* Shift up all elements of stack a by 1.
The first element becomes the last one */
void	ra(stack_head *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/*Shift up all elements of stack b by 1.
The first element becomes the last one */
void	rb(stack_head *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/* Execute rotate of the stack a and b at the same time */
void	rr(stack_head *a, stack_head *b)
{
	ra(a);
	rb(b);
}

/* ---------- Reverse Rotate ---------- */

/* Main function for rotate elements of the stack 
The last element becomes the first one */
void	reverse_rotate(stack_head *stack)
{
	stack_node	*to_last;

	if (!stack->head || !stack->head->next)
		return ;
	to_last = stack->head;
	while (to_last->next->next)
		to_last = to_last->next;
	to_last->next->next = stack->head;
	stack->head = to_last->next;
	to_last->next = NULL;
}

/* Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	rra(stack_head *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/* Shift down all elements of stack b by 1.
The last element becomes the first one. */
void	rrb(stack_head *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/* Execute reverse rotate of the stack a and b at the same time */
void	rrr(stack_head *a, stack_head *b)
{
	rra(a);
	rrb(b);
}
