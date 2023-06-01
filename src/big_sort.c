/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/01 13:46:35 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Main function to sort in ascending order a stack with more than 5 numbers*/
void	sort_big_stack(t_stack **a, t_stack **b)
{
	int			best_cost_posix;
	t_cost_tab	*table;
	t_cost_tab	*curr;

	exec_initial_moves(a, b);
	sort_stack_of_3(a);
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
	if (find_largest(a) > stack_size(a) / 2)
		while (find_largest(a) != stack_size(a) - 1)
			rra(a);
	else
		while (find_largest(a) != stack_size(a) - 1)
			ra(a);
}
