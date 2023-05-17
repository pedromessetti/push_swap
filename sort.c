/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/17 16:58:26 by pmessett         ###   ########.fr       */
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
	if (stack_size(a) == 5)
		sort_stack_of_5(a, b, 0);
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
int	find_max_value(t_stack **stack, int size)
{
	int		max_val;
	int		i;
	t_stack	*current;

	i = -1;
	max_val = INT_MIN;
	current = *stack;
	while (current && ++i < size)
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

void	sort_stack_of_5(t_stack **a, t_stack **b, int option)
{
	while (stack_size(a) > 3)
		pb(a, b);
	sort_stack_of_3(a);
	if (option)
	{
		resort_stack_of_5_option(a, b);
		return ;
	}
	resort_stack_of_5(a, b);
}

void	resort_stack_of_5(t_stack **a, t_stack **b)
{
	int		b_curr_val;
	t_stack	*tmp;
	double	size;
	int		count_largest;
	int		r_count;

	while (*b)
	{
		size = stack_size(a);
		b_curr_val = (*b)->value;
		tmp = *a;
		while (tmp && tmp->value < b_curr_val)
			tmp = tmp->next;
		count_largest = stack_size(&tmp);
		if (count_largest > size / 2)
			r_count = size - count_largest;
		else
			r_count = count_largest;
		while (r_count)
		{
			if (size - count_largest <= size / 2)
				ra(a);
			else
				rra(a);
			r_count--;
		}
		pa(a, b);
		if (count_largest >= size / 2)
			r_count = size - count_largest;
		else
			r_count = count_largest + 1;
		while (r_count)
		{
			if (size - count_largest <= size / 2)
				rra(a);
			else
				ra(a);
			r_count--;
		}
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int		size;
	int		sum;
	int		med;
	t_stack	*tmp_b;
	int		best_cost;
	int		best_cost_index;
	du_cost	cost[5];

	while (stack_size(a) > 5)
	{
		size = stack_size(a);
		sum = sum_val(a);
		med = sum / size;
		if ((*a)->value < med)
			pb(a, b);
		else
			ra(a);
	}
	sort_stack_of_5(a, b, 1);
	tmp_b = *b;
	for (int i = 0; i < 5; i++)
	{
		cost[i].bf = find_bf(a, tmp_b->value);
		cost[i].val = tmp_b->value;
		cost[i].cost = calc_cost(cost[i].val, cost[i].bf, a, b);
		tmp_b = tmp_b->next;
	}
	best_cost = cost[0].cost;
	best_cost_index = 0;
	for (int i = 0; i < 5; i++)
	{
		if (cost[i].cost < best_cost)
		{
			best_cost_index = i;
			best_cost = cost[i].cost;
		}
	}
	move_bf_to_top(cost[best_cost_index].bf, a);
	move_num_to_top(cost[best_cost_index].val, b);
	pa(a, b);
	sort_stack(a, b);
}

void	move_bf_to_top(int val, t_stack **a)
{
	int	posix;

	posix = find_pos_on_stack(a, val);
	if (posix > stack_size(a) / 2)
	{
		posix -= 5;
		posix *= -1;
		while (posix > 0)
		{
			rra(a);
			posix--;
		}
	}
	else
	{
		while (posix > 0)
		{
			ra(a);
			posix--;
		}
	}
}

void	move_num_to_top(int val, t_stack **b)
{
	int	posix;

	posix = find_pos_on_stack(b, val);
	if (posix > stack_size(b) / 2)
	{
		posix -= 5;
		posix *= -1;
		while (posix > 0)
		{
			rrb(b);
			posix--;
		}
	}
	else
	{
		while (posix > 0)
		{
			rb(b);
			posix--;
		}
	}
}

int	find_bf(t_stack **a, int value)
{
	int		bf;
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a->value < value)
		tmp_a = tmp_a->next;
	bf = tmp_a->value;
	return (bf);
}

int	calc_cost(int num, int bf, t_stack **a, t_stack **b)
{
	int	cost;
	int	moves_to_put_num_on_top;
	int	moves_to_put_bf_on_top;

	cost = 0;
	moves_to_put_num_on_top = find_pos_on_stack(b, num);
	moves_to_put_bf_on_top = find_pos_on_stack(a, bf);
	if (moves_to_put_num_on_top > stack_size(b) / 2)
	{
		moves_to_put_num_on_top -= 5;
		moves_to_put_num_on_top *= -1;
	}
	if (moves_to_put_bf_on_top > stack_size(a) / 2)
	{
		moves_to_put_bf_on_top -= 5;
		moves_to_put_bf_on_top *= -1;
	}
	cost = moves_to_put_bf_on_top + moves_to_put_num_on_top;
	return (cost);
}

int	sum_val(t_stack **a)
{
	t_stack	*curr;
	int		sum;

	curr = *a;
	sum = 0;
	while (curr)
	{
		sum += curr->value;
		curr = curr->next;
	}
	return (sum);
}

void	resort_stack_of_5_option(t_stack **a, t_stack **b)
{
	int b_curr_val;
	t_stack *tmp;
	double size;
	int count_largest;
	int r_count;
	int i = 3;
	while (--i > 0)
	{
		size = stack_size(a);
		b_curr_val = (*b)->value;
		tmp = *a;
		while (tmp && tmp->value < b_curr_val)
			tmp = tmp->next;
		count_largest = stack_size(&tmp);
		if (count_largest > size / 2)
			r_count = size - count_largest;
		else
			r_count = count_largest;
		while (r_count)
		{
			if (size - count_largest <= size / 2)
				ra(a);
			else
				rra(a);
			r_count--;
		}
		pa(a, b);
		if (count_largest >= size / 2)
			r_count = size - count_largest;
		else
			r_count = count_largest + 1;
		while (r_count)
		{
			if (size - count_largest <= size / 2)
				rra(a);
			else
				ra(a);
			r_count--;
		}
	}
}