/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:33:31 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/02 15:24:16 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printchain(void)
{
	printf("\n");
	for (size_t i = 0; i < 20; i++)
		printf("-=");
	printf("\n");
}

int	main(int ac, char **av)
{
	int i;
	char **args;
	stack_node stack_a;
	stack_node stack_b;
	char *chain;
	chain = "-=";

	stack_a.top = NULL;
	stack_b.top = NULL;
	if (ac >= 2)
	{
		args = ft_split(av[1], 32);
		i = -1;
		while (args[++i])
			push(&stack_a, ft_atoi(args[i]));
		printchain();
		printf("\nstack_a: ");
		printStack(&stack_a);
		printf("stack_b: ");
		printStack(&stack_b);
		printchain();
		ft_swap(&stack_a);
		printf("\nsa\n\nstack_a: ");
		printStack(&stack_a);
		printchain();
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		printf("\npb pb pb\n\nstack_a: ");
		printStack(&stack_a);
		printf("\nstack_b: ");
		printStack(&stack_b);
		printchain();
	}
	else
		return (write(1, "Error\n", 6));
	return (0);
}