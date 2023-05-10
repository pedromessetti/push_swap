/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:33:31 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/10 22:52:31 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	stack_head	*stack_a;
	stack_head	*stack_b;

	if (ac < 2)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(stack_a);
	stack_b = init_stack(stack_b);
	check_and_push(av, stack_a, stack_b);
	if (stack_is_sorted(stack_a))
		exit(1);
	sort_stack(stack_a, stack_b, ac);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
