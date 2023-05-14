/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:41:58 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/13 22:44:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------- Push ---------- */

/* Take the first element at the top of a and put it at the top of b. */
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	write(1, "pb\n", 3);
}

/* Take the first element at the top of b and put it at the top of a. */
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	write(1, "pa\n", 3);
}

/* ---------- Swap ---------- */

/* Swap the first 2 elements at the top of the stack passes as parameter */
void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/* Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/* Swap the first 2 elements at the top of the stack a and b at the same time */
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

/* ---------- Rotate ---------- */

/* Main function for rotate elements of the stack 
The first element becomes the last one */
void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	tmp = last->next;
	while (last->next)
		last= last->next;
	last->next = *stack;
	*stack = tmp;
	last->next->next = NULL;
}

/* Shift up all elements of stack a by 1.
The first element becomes the last one */
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/*Shift up all elements of stack b by 1.
The first element becomes the last one */
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/* Execute rotate of the stack a and b at the same time */
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

/* ---------- Reverse Rotate ---------- */

/* Main function for rotate elements of the stack 
The last element becomes the first one */
void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

/* Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/* Shift down all elements of stack b by 1.
The last element becomes the first one. */
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/* Execute reverse rotate of the stack a and b at the same time */
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
