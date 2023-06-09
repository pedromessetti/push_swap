/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:02:33 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/01 13:37:52 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that iterates into the stack and returns the total size of it */
int	stack_size(t_stack **stack)
{
	int		count;
	t_stack	*curr;

	if (!stack)
		return (0);
	count = 0;
	curr = *stack;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

/*Free the allocated memory for the stacks*/
void	free_stack(t_stack **stack)
{
	t_stack	*curr;

	if (!stack)
		return ;
	while (*stack)
	{
		curr = (*stack)->next;
		(*stack)->val = 0;
		free(*stack);
		(*stack) = curr;
	}
}

/*Add a node at the beginning of the stack and return it*/
t_stack	*add_number_to_stack(int val)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

/*Add a new node at the end of the stack*/
void	add_tail_to_stack(t_stack **stack_head, t_stack *new_node)
{
	if (!stack_head)
		return ;
	if (!*stack_head)
		*stack_head = new_node;
	else
		(find_tail(*stack_head))->next = new_node;
}
