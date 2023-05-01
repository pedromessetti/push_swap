/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:33:31 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/01 15:34:24 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define STACK_LENGHT 11

int	top = -1;
int	stack[STACK_LENGHT];

int	push(int value)
{
	if (top >= STACK_LENGHT - 1)
		return (0);
	top++;
	stack[top] = value;
	return (1);
}

int	pop(void)
{
	int	result;

	if (top == -1)
		return (INT_MIN);
	result = stack[top];
	top--;
	return (result);
}

int	main(int ac, char **av)
{
	int i;
	char **result;

	if (ac == 2)
	{
		result = ft_split(av[1], ' ');
		printf("Unsorted args: %s\n", av[1]);
		i = -1;
		while (result[++i])
		{
			stack[i] = ft_atoi(result[i]);
			printf("push(%i)\n", stack[i]);
		}
		insertion_sort(stack, STACK_LENGHT);
		printf("Sorted args:");
		for (size_t i = 0; i < STACK_LENGHT; i++)
		{
			printf(" %i ", stack[i]);
		}
	}
	else
		return (write(1, "error\n", 6));
	return (0);
}