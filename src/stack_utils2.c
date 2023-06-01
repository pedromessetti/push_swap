/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:48:01 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/01 11:33:35 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Iterates into the stack and returns the last node*/
t_stack	*find_tail(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*Iterates into the stack and returns the position of the value on the stack*/
int	find_pos_on_stack(t_stack **stack, int val_to_find)
{
	t_stack	*curr;
	int		posix;

	curr = *stack;
	posix = 0;
	while (curr)
	{
		if (curr->val == val_to_find)
			return (posix);
		posix++;
		curr = curr->next;
	}
	return (-1);
}

/*Finds the smallest value on the stack and
 returns his position related to the top*/
int	find_smallest(t_stack **stack)
{
	int		smallest;
	int		curr_posix;
	t_stack	*curr;
	t_stack	*tmp;

	curr_posix = 0;
	tmp = *stack;
	smallest = (*stack)->val;
	curr = *stack;
	while (curr)
	{
		if (curr->val < smallest)
			smallest = curr->val;
		curr = curr->next;
	}
	while (tmp->val != smallest)
	{
		tmp = tmp->next;
		curr_posix++;
	}
	return (curr_posix);
}

/*Finds the largest value on the stack and
 returns his position related to the top*/
int	find_largest(t_stack **stack)
{
	int		largest;
	int		max_pos;
	int		curr_pos;
	t_stack	*curr;

	largest = INT_MIN;
	max_pos = -1;
	curr_pos = 0;
	curr = *stack;
	while (curr)
	{
		if (curr->val > largest)
		{
			largest = curr->val;
			max_pos = curr_pos;
		}
		curr = curr->next;
		curr_pos++;
	}
	return (max_pos);
}
