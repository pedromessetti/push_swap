/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:02:33 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/10 22:59:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that iterates into the stack and prints each value */
void	print_stack(stack_head *stack)
{
	stack_node	*current;

	current = stack->head;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

/* Function that iterates into the stack and returns the total size of it */
int	stack_size(stack_head *stack)
{
	int			count;
	stack_node	*current;

	if (!stack)
		return (0);
	count = 0;
	current = stack->head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/* Free the allocated memory for the stacks */
void	free_stacks(stack_head *a, stack_head *b)
{
	stack_node	*current;
	stack_node	*tmp;

	current = a->head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(a);
	current = b->head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(b);
}

/* Initialize and set the allocated memory for the stack */
stack_head	*init_stack(stack_head *stack)
{
	stack = (stack_head *)malloc(sizeof(stack_head));
	if (!stack)
		exit(1);
	return (stack);
}
