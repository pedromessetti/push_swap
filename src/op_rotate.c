/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:48:03 by pedro             #+#    #+#             */
/*   Updated: 2023/05/19 13:46:58 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		last = last->next;
	last->next = *stack;
	*stack = tmp;
	last->next->next = NULL;
}

/* Shift up all elements of stack A by 1.
The first element becomes the last one */
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/*Shift up all elements of stack B by 1.
The first element becomes the last one */
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/* Execute rotate of the stack A and stack B at the same time */
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
