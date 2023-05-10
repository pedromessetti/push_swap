/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/05 19:38:26 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if the stack is already sorted
   Return 1 if the stack is sorted
   Return 0 if the stack is not sorted */
int	stack_is_sorted(t_stack *a)
{
	int		prev_value;
	t_stack	*current;

	if (!a->top || !a->top->next)
		return (1);
	prev_value = a->top->value;
	current = a->top->next;
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

int	find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*current;

	smallest = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

int	find_largest(t_stack *stack)
{
	int		largest;
	t_stack	*current;

	largest = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value > largest)
			largest = current->value;
		current = current->next;
	}
	return (largest);
}

void	sort_stack(t_stack *a, t_stack *b, int ac)
{
	int	smallest;
	int	largest;
	int	i;

	i = 0;
	while (a->top)
	{
		smallest = find_smallest(a);
		while (a->top->value != smallest)
		{
			if (a->top->index > i / 2)
				rra(a);
			else
				ra(a);
		}
		pb(a, b);
		i++;
	}
	largest = find_largest(b);
	while (stack_size(a) != ac - 2)
	{
		if (stack_size(a) != ac - 2 && b->top->value == largest)
		{
			if (stack_size(a) - 2 != ac)
				pa(a, b);
			printf("value1: %d, value2: %d\n", stack_size(a), ac - 2);
			if (stack_size(a) != ac - 2)
				largest = find_largest(b);
		}
		if (stack_size(a) != ac - 2 && b->top->index > i / 2)
		{
			rrb(b);
		}
		else if (stack_size(a) != ac - 2)
			rb(b);
		i--;
	}
}
