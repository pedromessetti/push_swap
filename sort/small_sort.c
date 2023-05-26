/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:10:47 by pedro             #+#    #+#             */
/*   Updated: 2023/05/19 16:30:00 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Sort in ascending order a stack with 2 different numbers*/
void	sort_stack_of_2(t_stack **a)
{
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

/*Sort in ascending order a stack with 3 different numbers*/
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

/*Main function to sort a stack of 5 different numbers*/
void	sort_stack_of_5(t_stack **a, t_stack **b, int option)
{
	while (stack_size(a) > 3)
		pb(a, b);
	sort_stack_of_3(a);
	if (option)
	{
		sort_stack_of_5__aux_option(a, b, 3);
		return ;
	}
	sort_stack_of_5__aux(a, b);
}

/*Auxiliar function to sort the stack of 5 different numbers 
(stack A must be already in ascending order)*/
void	sort_stack_of_5__aux(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		size;
	int		count_largest;
	int		r_count;

	while (*b)
	{
		size = stack_size(a);
		tmp = *a;
		while (tmp && tmp->val < (*b)->val)
			tmp = tmp->next;
		count_largest = stack_size(&tmp);
		if (count_largest > size / 2)
			r_count = size - count_largest;
		else
			r_count = count_largest;
		exec_rotate_1(a, r_count, size, count_largest);
		pa(a, b);
		if (count_largest >= size / 2)
			r_count = size - count_largest;
		else
			r_count = count_largest + 1;
		exec_rotate_2(a, r_count, size, count_largest);
	}
}
