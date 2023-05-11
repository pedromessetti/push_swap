/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:40:09 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/11 16:19:35 by pmessett         ###   ########.fr       */
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
	write(1, "Stack already sorted\n", 21);
	return (1);
}

void	sort_stack(t_stack **a, t_stack **b)
{
    t_stack	*current;

    if (!*a || !(*a)->next)
        return ;
    while (*a)
    {
        current = *a;
        *a = (*a)->next;
        if (!*b || current->value > (*b)->value)
            pb(&current, b);
        else
        {
            while (*b && current->value < (*b)->value)
                rb(b);
            pb(&current, b);
            while (*b && (*b)->value < find_last(*b)->value)
                rrb(b);
        }
    }
    while (*b)
        rb(b);
    while (*b)
    {
        current = *b;
        *b = (*b)->next;
        pa(a, &current);
    }
}
