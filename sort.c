/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/10 23:18:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if the stack is already sorted
   Return 1 if the stack is sorted
   Return 0 if the stack is not sorted */
int	stack_is_sorted(stack_head *a)
{
	int		prev_value;
	stack_node	*current;

	if (!a->head || !a->head->next)
		return (1);
	prev_value = a->head->value;
	current = a->head->next;
	while (current)
	{
		if (current->value < prev_value)
			return (0);
		prev_value = current->value;
		current = current->next;
	}
	write(1, "Stack already sorted\n", 21);
	return (1);
}

int	find_smallest(stack_head *stack)
{
	int		smallest;
	stack_node	*current;

	smallest = stack->head->value;
	current = stack->head->next;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

int	find_largest(stack_head *stack)
{
	int		largest;
	stack_node	*current;

	largest = stack->head->value;
	current = stack->head->next;
	while (current)
	{
		if (current->value > largest)
			largest = current->value;
		current = current->next;
	}
	return (largest);
}

void	sort_stack(stack_head *a, stack_head *b, int ac)
{
	int	smallest;
	int	largest;
	int	i;

	i = 0;
	while (a->head)
	{
		smallest = find_smallest(a);
		while (a->head->value != smallest)
		{
			if (a->head->index > i / 2)
				rra(a);
			else
				ra(a);
		}
		pb(a, b);
		i++;
	}
	largest = find_largest(b);
	while (stack_size(a) != ac - 1)
	{
		if (stack_size(a) != ac - 1 && b->head->value == largest)
		{
			if (stack_size(a) - 2 != ac)
				pa(a, b);
			if (stack_size(a) != ac - 1)
				largest = find_largest(b);
		}
		if (stack_size(a) != ac - 1 && b->head->index > i / 2)
		{
			rrb(b);
		}
		else if (stack_size(a) != ac - 1)
			rb(b);
		i--;
	}
}
