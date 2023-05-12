/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:33:31 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/12 16:35:39 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(1);
	check_and_push(av, &stack_a);
	if (stack_is_sorted(stack_a))
		exit(1);
	define_sort(&stack_a, &stack_b, ac-1);
	print_stack(&stack_a);
	print_stack(&stack_b);
	free_stacks(&stack_a);
	free_stacks(&stack_b);
	return (0);
}
