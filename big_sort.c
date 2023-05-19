/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/19 05:51:15 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Main function to sort in ascending order a stack with more than 5 numbers*/
void	sort_big_stack(t_stack **a, t_stack **b)
{
	int			best_cost_posix;
	cost_tab	*table;
	cost_tab	*curr;

	exec_initial_moves(a, b);
	sort_stack_of_5(a, b, 1);
	while (stack_size(b) > 0)
	{
		table = NULL;
		set_cost_table(a, b, &table);
		best_cost_posix = get_best_cost_posix(&table);
		curr = table;
		while (curr && best_cost_posix-- > 0)
			curr = curr->next;
		move_bf_to_top(curr->bf, a);
		move_num_to_top(curr->val, b);
		free_cost_tab(&table);
		pa(a, b);
	}
	while (find_largest(a) != stack_size(a) - 1)
		ra(a);
}

/*Auxiliar function to sort the stack of 5 different numbers 
(stack A must be already in ascending order)*/
void	sort_stack_of_5__aux_option(t_stack **a, t_stack **b)
{
	int		b_curr_val;
	t_stack	*tmp;
	int	size;
	int		count_largest;
	int		r_count;
	int		i;

	i = 3;
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
		exec_rotate(a, r_count, size, count_largest, 0);
		pa(a, b);
		if (count_largest >= size / 2)
			r_count = size - count_largest;
		else
			r_count = count_largest + 1;
		exec_rotate(a, r_count, size, count_largest, 1);
	}
}
