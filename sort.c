/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/16 10:12:42 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if the stack is already sorted
   Return 1 if the stack is sorted
   Return 0 if the stack is not sorted */
int	stack_is_sorted(t_stack **stack)
{
	int		prev_value;
	t_stack	*current;

	if (!stack || !(*stack)->next)
		return (1);
	prev_value = (*stack)->value;
	current = (*stack)->next;
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

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
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

/*Define which sort algorithm the program should choose*/
void	define_sort(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next)
		return ;
	if (stack_size(a) == 3)
		sort_stack_of_3(a);
	else
		sort_stack(a, b);
}

// Finds the minimum value in the stack
int	find_min_value(t_stack **stack)
{
	int		min_val;
	t_stack	*current;

	min_val = INT_MAX;
	current = *stack;
	while (current != NULL)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
		}
		current = current->next;
	}
	return (min_val);
}

// Finds the maximum value in the stack
int	find_max_value(t_stack **stack)
{
	int		max_val;
	t_stack	*current;

	max_val = INT_MIN;
	current = *stack;
	while (current != NULL)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
		}
		current = current->next;
	}
	return (max_val);
}

// Finds the position of the maximum value in the stack
int	find_largest(t_stack **stack)
{
	int		max_val;
	int		max_pos;
	int		current_pos;
	t_stack	*current;

	max_val = INT_MIN;
	max_pos = -1;
	current_pos = 0;
	current = *stack;
	while (current)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (max_pos);
}

void	sort_stack_of_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

/*Sort in ascending order a stack with 3 elements*/
void	sort_stack_of_3(t_stack **a)
{
	while (!stack_is_sorted(a))
	{
		if ((find_smallest(a) == 1 && find_largest(a) == 2)
			|| (find_smallest(a) == 2 && find_largest(a) == 0)
			|| (find_smallest(a) == 0 && find_largest(a) == 1))
			sa(a);
		else if ((find_smallest(a) == 2 && find_largest(a) == 1))
			rra(a);
		else if (!stack_is_sorted(a))
			ra(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int		hold_first;
	int		hold_second;
	int		move_count_first;
	int		move_count_second;
	int		hold_sec_pos;
	t_stack	*current;
	int		size;
	int		current_value;

	if (!*a)
		return ;
	print_stack(a);
	print_stack(b);
	move_count_first = 0;
	size = stack_size(a);
	move_count_second = 0;
	//Scan stack_a from the top to confirm if one of the numbers from Chunk1 exist in the stack and stores his value in hold_fist variable
	//Also count the amout of movements necessary to bring the value to the top of the stack
	current = *a;
	while (current)
	{
		if (current->value > 0 && current->value < 20)
		{
			hold_first = current->value;
			break ;
		}
		move_count_first++;
		current = current->next;
	}
	//Scan stack_a from the bottom and see if a different number from Chunk1 exist in the stack and stores his value in hold_second variable
	//Also count the amout of movements necessary to bring the value to the top of the stack
	current = *a;
	while (current)
	{
		if (current->value > 0 && current->value < 20)
		{
			hold_second = current->value;
			hold_sec_pos = move_count_second;
		}
		move_count_second++;
		current = current->next;
	}
	move_count_second = size - hold_sec_pos;
	//Compare how many moves it would take to get the values to the top and decides wich choice is the best
	if (move_count_first > move_count_second)
	{
		current_value = hold_second;
		rra_for_(a, move_count_second);
	}
	else
	{
		current_value = hold_first;
		ra_for_(a, move_count_first);
	}
	while (!*b || !(*b)->next)
		pb(a, b);
	//Check if the number that we are pushing is either bigger or smaller than all the other numbers in stack_b
	current = *b;
	while (current)
	{
		current = current->next;
	}
}

int	pop(t_stack **stack)
{
	int		val;
	t_stack	*tmp;

	if (!(*stack))
		return (-1);
	val = (*stack)->value;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (val);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	smallest;
	int	largest;
	int	size;

	size = stack_size(a);
	i = 0;
	while (stack_size(a) > 0 && i <= size)
	{
		if (i == 0)
		{
			smallest = (*a)->value;
			while (stack_size(a) > 0)
			{
				if ((*a)->value < smallest)
					smallest = (*a)->value;
				pb(a, b);
				if (stack_size(b) > 1 && (*b)->value > (*b)->next->value)
					sb(b);
			}
			while (stack_size(b) > 0 && (*b)->value != smallest)
			{
				if ((*b)->value < smallest)
					ra(a);
				else if ((*b)->value != smallest && stack_size(b) > 1)
					rb(b);
				else
					pa(a, b);
			}
		}
		print_stack(a);
		print_stack(b);
		pa(a, b);
		i++;
	}
	largest = (*b)->value;
	while (i > 0)
	{
		while ((*b)->value != largest)
		{
			if (stack_size(b) == 1 || (*b)->next->value == largest)
				rb(b);
			else if ((*b)->value > (*b)->next->value)
				sb(b);
			else
				ra(a);
		}
		pa(a, b);
		largest = (*b)->value;
		i--;
	}
}

void	rra_for_(t_stack **a, int move_count)
{
	while (move_count > 0)
	{
		rra(a);
		move_count--;
	}
}

void	ra_for_(t_stack **a, int move_count)
{
	while (move_count > 0)
	{
		ra(a);
		move_count--;
	}
}
