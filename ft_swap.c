/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:01:36 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/02 10:56:23 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(stack_node *stack)
{
	if (!stack->top || !stack->top->next)
		return ;

	stack_node *first = stack->top;
	stack_node *second = stack->top->next;

	int tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}