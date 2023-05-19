/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:17:05 by pedro             #+#    #+#             */
/*   Updated: 2023/05/19 05:16:01 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Calculate and moves best friend to top of stack A*/
void	move_bf_to_top(int val, t_stack **a)
{
	int	posix;

	posix = find_pos_on_stack(a, val);
	if (posix > stack_size(a) / 2)
	{
		posix -= stack_size(a);
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

/*Calculate and moves number to top of stack A*/
void	move_num_to_top(int val, t_stack **b)
{
	int	posix;

	posix = find_pos_on_stack(b, val);
	if (posix > stack_size(b) / 2)
	{
		posix -= stack_size(b);
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

/*Iterates in stack A and returns the best friend for the value*/
int	find_bf(t_stack **a, int val)
{
	int		bf;
	int		res;
	int		counter;
	t_stack	*tmp_a;

	tmp_a = *a;
	counter = INT_MAX;
	bf = INT_MAX;
	while (tmp_a)
	{
		res = tmp_a->val - val;
		if ((res < counter) && (tmp_a->val > val))
		{
			counter = res;
			bf = tmp_a->val;
		}
		tmp_a = tmp_a->next;
	}
	if (bf == INT_MAX)
		return (-1);
	return (bf);
}

/*Calcutes and returns the sum of the amount of movements to put the number and his best friend on top of their stacks*/
int	calc_cost(int num, int bf, t_stack **a, t_stack **b)
{
	int	cost;
	int	moves_to_put_num_on_top;
	int	moves_to_put_bf_on_top;

	cost = 0;
	moves_to_put_num_on_top = find_pos_on_stack(b, num); //0
	moves_to_put_bf_on_top = find_pos_on_stack(a, bf); //4
	if (moves_to_put_num_on_top > stack_size(b) / 2)
	{
		moves_to_put_num_on_top -= stack_size(b);
		moves_to_put_num_on_top *= -1;
	}
	if (moves_to_put_bf_on_top > stack_size(a) / 2)
	{
		moves_to_put_bf_on_top -= stack_size(a);
		moves_to_put_bf_on_top *= -1;
	}
	cost = moves_to_put_bf_on_top + moves_to_put_num_on_top;
	return (cost);
}

/*Returns the sum of all of the values in stack A*/
int	sum_val(t_stack **a)
{
	t_stack	*curr;
	int		sum;

	curr = *a;
	sum = 0;
	while (curr)
	{
		sum += curr->val;
		curr = curr->next;
	}
	return (sum);
}
