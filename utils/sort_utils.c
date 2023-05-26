/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:53:57 by pedro             #+#    #+#             */
/*   Updated: 2023/05/19 16:28:04 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rotate_2(t_stack **a, int rotate_count, int size,
		int count_largest)
{
	if (!*a)
		return ;
	while (rotate_count)
	{
		if (size - count_largest <= size / 2)
			rra(a);
		else
			ra(a);
		rotate_count--;
	}
}

void	exec_rotate_1(t_stack **a, int rotate_count, int size,
		int count_largest)
{
	if (!*a)
		return ;
	while (rotate_count)
	{
		if (size - count_largest <= size / 2)
			ra(a);
		else
			rra(a);
		rotate_count--;
	}
}
