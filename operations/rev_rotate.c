/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:48:03 by pedro             #+#    #+#             */
/*   Updated: 2023/05/18 20:58:27 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* Shift down all elements of stack A by 1.
The last element becomes the first one. */
void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/* Shift down all elements of stack B by 1.
The last element becomes the first one. */
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/* Execute reverse rotate of the stack A and stack B at the same time */
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
