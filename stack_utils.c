/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:02:33 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/05 19:15:42 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that iterates into the stack and prints each value */
void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack->top;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

/* Function that iterates into the stack and returns the total size of it */
int	stack_size(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

/* Free the allocated memory for the stacks */
void	free_stacks(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*tmp;

	current = a->top;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(a);
	current = b->top;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(b);
}

/* Initialize and set the allocated memory for the stack */
t_stack	*init_stack(t_stack *stack)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	return (stack);
}
