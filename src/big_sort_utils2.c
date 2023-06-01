/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 05:15:25 by pedro             #+#    #+#             */
/*   Updated: 2023/06/01 11:31:21 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Calculates the medium value between all numbers from stack A
	if the number are bellow the medium value, pb(), if is above ra().*/
void	exec_initial_moves(t_stack **a, t_stack **b)
{
	int	size_a;
	int	sum;
	int	med;

	size_a = 0;
	sum = 0;
	med = 0;
	while (stack_size(a) > 3)
	{
		size_a = stack_size(a);
		sum = sum_val(a);
		med = sum / size_a;
		if ((*a)->val < med)
			pb(a, b);
		else
			ra(a);
	}
}

/*Auxiliar function to set the cost table*/
void	set_cost_table(t_stack **a, t_stack **b, t_cost_tab **table)
{
	int		bf;
	int		val;
	int		val_cost;
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		val = tmp_b->val;
		bf = find_bf(a, val);
		val_cost = calc_cost(val, bf, a, b);
		if (!*table)
			(*table) = add_cost(val, bf, val_cost);
		else
			add_tail_to_cost_table(table, add_cost(val, bf, val_cost));
		tmp_b = tmp_b->next;
	}
}

/*Calculate and returns the posix of the best cost on the cost table*/
int	get_best_cost_posix(t_cost_tab **table)
{
	t_cost_tab	*curr;
	int			best_cost_posix;
	int			best_cost_val;
	int			i;

	curr = *table;
	best_cost_val = curr->cost;
	i = 0;
	best_cost_posix = 0;
	while (curr)
	{
		if (curr->cost < best_cost_val)
		{
			best_cost_posix = i;
			best_cost_val = curr->cost;
			i++;
		}
		else
			i++;
		curr = curr->next;
	}
	return (best_cost_posix);
}
