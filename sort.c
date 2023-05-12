/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/12 16:37:44 by pmessett         ###   ########.fr       */
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

	if (!a || !a->next)
		return (1);
	prev_value = a->value;
	current = a->next;
	while (current)
	{
		if (current->value < prev_value)
			return (0);
		prev_value = current->value;
		current = current->next;
	}
	// write(1, "Stack already sorted\n", 21);
	return (1);
}

/*Finds the smallest value on the stack and returns his position related to the top*/
int	find_smallest(t_stack **stack)
{
	int		smallest;
	int		count;
	t_stack	*current;
	t_stack	*tmp;

	count = 0;
	tmp = *stack;
	smallest = (*stack)->value;
	current = *stack;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	while (tmp->value != smallest)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	find_largest(t_stack **stack)
{
	int		largest;
	int		count;
	t_stack	*current;
	t_stack	*tmp;

	count = 0;
	tmp = *stack;
	largest = (*stack)->value;
	current = *stack;
	while (current)
	{
		if (current->value > largest)
			largest = current->value;
		current = current->next;
	}
	while (tmp->value != largest)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	define_sort(t_stack **a, int ac)
{
	if (!*a || !(*a)->next)
		return ;
	if (ac == 3)
		sort_stack_of_3(a);
}

void	sort_stack_of_3(t_stack **a)
{
	while (!stack_is_sorted((*a)))
	{
		if ((find_smallest(a) == 1 && find_largest(a) == 2) || (find_smallest(a) == 2 && find_largest(a) == 0) || (find_smallest(a) == 0 && find_largest(a) == 1))
			sa(a);
		else if((find_smallest(a) == 2 && find_largest(a) == 1))
			rra(a);
		else
			ra(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next)
		return ;
	while (*a)
	{
		if (find_smallest(a) > (stack_size(a) / 2))
		{
			while (find_smallest(a) != 0)
				rra(a);
			pb(a, b);
		}
		else
		{
			while (find_smallest(a) != 0)
				ra(a);
			pb(a, b);
		}
	}
	while (*b)
		pa(a, b);
}
