/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:02:33 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/11 16:23:11 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that iterates into the stack and prints each value */
void	print_stack(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

/* Function that iterates into the stack and returns the total size of it */
int	stack_size(t_stack **stack)
{
	int		count;
	t_stack	*current;

	if (!stack)
		return (0);
	count = 0;
	current = *stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/* Free the allocated memory for the stacks */
void	free_stacks(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->value = 0;
		free(*stack);
		(*stack) = tmp;
	}
}

/* Initialize and set the allocated memory for the stack */
t_stack	*init_stack(void)
{
	t_stack *stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	return (stack);
}

void	add_tail(t_stack **stack_head, t_stack *new_node)
{
	if (!stack_head)
		return ;
	if (!*stack_head)
		*stack_head = new_node;
	else
		(find_last(*stack_head))->next = new_node;
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*add_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
