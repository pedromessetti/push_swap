/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:40:13 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/31 14:32:24 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function that checks if there is an duplicated argument 
   Return 1 if there is any duplicated argument
   Return 0 if there is no duplicated argument */
int	check_for_dup(long tmp, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

/* Check if there are correct arguments and pushes them to the stack */
void	check_and_push(char **av, t_stack **a)
{
	int		i;
	long	tmp;

	i = 0;
	while (av[++i])
	{
		tmp = ft_atoi(av[i]);
		if (!is_numeric(av[i]) || check_for_dup(tmp, av, i) || (tmp > INT_MAX
				|| tmp < INT_MIN))
		{
			free_stack(a);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (!*a)
			*a = add_number_to_stack(tmp);
		else
			add_tail_to_stack(a, add_number_to_stack(tmp));
	}
}

/*Define which sort algorithm the program should choose*/
void	define_sort(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next)
		return ;
	else if (stack_size(a) == 2)
		sort_stack_of_2(a);
	else if (stack_size(a) <= 3)
		sort_stack_of_3(a);
	else if (stack_size(a) <= 5)
		sort_stack_of_5(a, b, 0);
	else
		sort_big_stack(a, b);
}

/* Check if the stack is already sorted
   Return 1 if the stack is sorted
   Return 0 if the stack is not sorted */
int	stack_is_sorted(t_stack **stack)
{
	int		prev_val;
	t_stack	*curr;

	if (!stack || !(*stack)->next)
		return (1);
	prev_val = (*stack)->val;
	curr = (*stack)->next;
	while (curr)
	{
		if (curr->val < prev_val)
			return (0);
		prev_val = curr->val;
		curr = curr->next;
	}
	return (1);
}
