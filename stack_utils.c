/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:02:33 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/18 11:08:24 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that iterates into the stack and prints each value */
void	print_stack(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

void	print_cost(du_cost **cost_tab)
{
	du_cost	*curr;

	curr = *cost_tab;
	while (curr)
	{
		printf("Value: %d\nBest Friend: %d\nCost: %d\n", curr->val, curr->bf, curr->cost);
		curr = curr->next;
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

/* Free the allocated memory for the cost table */
void	free_cost_tab(du_cost **cost_tab)
{
	du_cost	*tmp;

	if (!cost_tab)
		return ;
	while (*cost_tab)
	{
		tmp = (*cost_tab)->next;
		(*cost_tab)->val = 0;
		(*cost_tab)->bf = 0;
		(*cost_tab)->cost = 0;
		free(*cost_tab);
		(*cost_tab) = tmp;
	}
}

/* Initialize and set the allocated memory for the stack */
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	return (stack);
}

void	add_tail_to_stack(t_stack **stack_head, t_stack *new_node)
{
	if (!stack_head)
		return ;
	if (!*stack_head)
		*stack_head = new_node;
	else
		(find_last_stack(*stack_head))->next = new_node;
}

void	add_tail_to_cost_table(du_cost **stack_head, du_cost *new_node)
{
	if (!stack_head)
		return ;
	if (!*stack_head)
		*stack_head = new_node;
	else
		(find_last_cost(*stack_head))->next = new_node;
}

t_stack	*find_last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

du_cost	*find_last_cost(du_cost *cost_table)
{
	if (!cost_table)
		return (NULL);
	while (cost_table->next)
		cost_table = cost_table->next;
	return (cost_table);
}

t_stack	*add_number_to_stack(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

du_cost	*add_cost(int val, int bf, int val_cost)
{
	du_cost	*new_node;

	new_node = (du_cost *)malloc(sizeof(du_cost));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->bf = bf;
	new_node->cost = val_cost;
	new_node->next = NULL;
	return (new_node);
}

int	find_pos_on_stack(t_stack **stack, int value_to_find)
{
	t_stack	*curr;
	int		i;

	curr = *stack;
	i = 0;
	while (curr)
	{
		if (curr->value == value_to_find)
			return (i);
		i++;
		curr = curr->next;
	}
	return (-1);
}

/*Calculates the medium value between all numbers from stack_a
	if the number are bellow the medium value, pb(), if is above ra().*/
void	auxiliar_1(t_stack **a, t_stack **b)
{
	int size_a = 0;
	int sum = 0;
	int med = 0;
	while (stack_size(a) > 5)
	{
		size_a = stack_size(a);
		sum = sum_val(a);
		med = sum / size_a;
		if ((*a)->value < med)
			pb(a, b);
		else
			ra(a);
	}
}