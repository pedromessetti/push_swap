/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:48:03 by pedro             #+#    #+#             */
/*   Updated: 2023/05/19 08:34:43 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Main function to swap the first 2 elements at the top of the stack passes as parameter */
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

/* Swap the first 2 elements at the top of stack A.
Do nothing if there is only one or no elements. */
void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/* Swap the first 2 elements at the top of stack B.
Do nothing if there is only one or no elements. */
void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/* Swap the first 2 elements at the top of the stack A and stack B at the same time */
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
