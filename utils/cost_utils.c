/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:42:27 by pedro             #+#    #+#             */
/*   Updated: 2023/05/19 17:02:48 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free the allocated memory for the cost table */
void	free_cost_tab(t_cost_tab **table)
{
	t_cost_tab	*tmp;

	if (!table)
		return ;
	while (*table)
	{
		tmp = (*table)->next;
		(*table)->bf = 0;
		(*table)->val = 0;
		(*table)->cost = 0;
		free(*table);
		(*table) = tmp;
	}
}

/*Add a new node at the beginning of the cost table*/
t_cost_tab	*add_cost(int val, int bf, int val_cost)
{
	t_cost_tab	*new_node;

	new_node = (t_cost_tab *)malloc(sizeof(t_cost_tab));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->bf = bf;
	new_node->cost = val_cost;
	new_node->next = NULL;
	return (new_node);
}

/*Add a new node at the end of the cost table*/
void	add_tail_to_cost_table(t_cost_tab **table_head, t_cost_tab *new_node)
{
	if (!table_head)
		return ;
	if (!*table_head)
		*table_head = new_node;
	else
		(find_last_cost(*table_head))->next = new_node;
}

/*Iterates into the cost table and returns the last node*/
t_cost_tab	*find_last_cost(t_cost_tab *table)
{
	if (!table)
		return (NULL);
	while (table->next)
		table = table->next;
	return (table);
}
