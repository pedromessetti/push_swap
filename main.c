/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:33:31 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/04 16:05:58 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printchain(void)
{
	printf("\n");
	for (size_t i = 0; i < 20; i++)
		printf("-=");
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		i;
	long	tmp;

	i = -1;
	if (ac < 2)
		return (write(1, "Error: too few arguments\n", 25));
	stack_a = init_stack(stack_a);
	stack_b = init_stack(stack_b);
	if (ac == 2)
		args = ft_split(av[1], 32);
	else
	{
		i = 0;
		args = av;
	}
	check_and_push(args, stack_a, stack_b, i);
	if (stack_is_sorted(stack_a))
		exit(1);
	// printf("top = %i\n", stack_a->top->value);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
