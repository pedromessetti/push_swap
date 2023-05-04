/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:33:31 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/04 11:21:00 by pmessett         ###   ########.fr       */
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
	t_stack *stack_a;
	t_stack *stack_b;
	char **args;
	int i = -1;

	if (ac < 2)
		return (write(1, "Error: too few arguments\n", 25));
	stack_a = NULL;
	stack_b = NULL;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (ac == 2)
		args = ft_split(av[1], 32);
	else
	{
		i = 0;
		args = av;
	}
	long int tmp;
	while (args[++i])
	{
		if (!ft_isnumeric(args[i]))
		{
			free_stacks(stack_a, stack_b);
			return (write(1, "Error: non integer argument\n", 28));
		}
		tmp = ft_atoi(args[i]);
		if (tmp >= INT_MAX || tmp <= INT_MIN)
		{
			free_stacks(stack_a, stack_b);
			return (write(1, "Error: argument is bigger or smallest than an integer\n", 54));
		}
		if (check_for_dup(tmp, av, i))
		{
			free_stacks(stack_a, stack_b);
			return (write(1, "Error: duplicate arguments\n", 28));
		}
		push(stack_a, tmp);
	}

	// printf("%i\n", INT_MAX);
	// printf("%li\n", INT_MIN);
	// swap(stack_a);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// rotate(stack_a);
	// rotate(stack_b);
	// reverse_rotate(stack_a);
	// reverse_rotate(stack_b);
	// swap(stack_a);
	// pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}