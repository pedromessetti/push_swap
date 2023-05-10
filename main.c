/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:33:31 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/08 09:31:38 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(stack_a);
	stack_b = init_stack(stack_b);
	check_and_push(ac, av, stack_a, stack_b);
	if (stack_is_sorted(stack_a))
		exit(1);
	print_stack(stack_a);
	sort_stack(stack_a, stack_b, ac);
	print_stack(stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
