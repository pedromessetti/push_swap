/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:53:57 by pedro             #+#    #+#             */
/*   Updated: 2023/05/19 05:54:49 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Finds the smallest value on the stack and returns his position related to the top*/
int	find_smallest(t_stack **stack)
{
	int		smallest;
	int		count;
	t_stack	*curr;
	t_stack	*tmp;

	count = 0;
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
		count++;
	}
	return (count);
}

// Finds the position of the maximum value in the stack
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

void	exec_rotate(t_stack **a, int rotate_count, int size, int count_largest,
		int option)
{
	if (!*a)
		return ;
	while (rotate_count)
	{
		if (option)
		{
			if (size - count_largest <= size / 2)
				rra(a);
			else
				ra(a);
		}
		else
		{
			if (size - count_largest <= size / 2)
				ra(a);
			else
				rra(a);
		}
		rotate_count--;
	}
}
