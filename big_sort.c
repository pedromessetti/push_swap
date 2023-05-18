/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/18 21:00:41 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Main function to sort in ascending order a stack with more than 5 numbers*/
void	sort_big_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		best_cost;
	int		best_cost_index;
	cost_tab	*cost;
	int		bf;
	int		val;
	int		val_cost;
	cost_tab	*curr;
	int		j;

	auxiliar_1(a, b);
	sort_stack_of_5(a, b, 1);
	while (stack_size(b) > 0)
	{
		cost = NULL;
		tmp_b = *b;
		while (tmp_b)
		{
			val = tmp_b->val;
			bf = find_bf(a, val);
			val_cost = calc_cost(val, bf, a, b);
			if (!cost)
				cost = add_cost(val, bf, val_cost);
			else
				add_tail_to_cost_table(&cost, add_cost(val, bf, val_cost));
			tmp_b = tmp_b->next;
		}
		curr = cost;
		best_cost = curr->cost;
		j = 0;
		best_cost_index = 0;
		while (curr)
		{
			if (curr->cost < best_cost)
			{
				best_cost_index = j;
				best_cost = curr->cost;
				j++;
			}
			else
				j++;
			curr = curr->next;
		}
		curr = cost;
		while (curr && best_cost_index > 0)
		{
			best_cost_index--;
			curr = curr->next;
		}
		move_bf_to_top(curr->bf, a);
		move_num_to_top(curr->val, b);
		free_cost_tab(&cost);
		pa(a, b);
	}
	while (find_largest(a) != stack_size(a)-1)
		ra(a);
}

/*Auxiliar function to sort the stack of 5 different numbers 
(stack A must be already in ascending order)*/
void	sort_stack_of_5__aux_option(t_stack **a, t_stack **b)
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
		b_curr_val = (*b)->val;
		tmp = *a;
		while (tmp && tmp->val < b_curr_val)
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
