/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:40:13 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/10 22:41:41 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if there is a numeric character in the string pointed by s
   Return 1 if the string is a numeric char
   Return 0 if find something else */
int	is_numeric(char *s)
{
	int	i;

	i = 0;
	if (s[0] == 45 && is_digit(s[1]))
		i++;
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Check if the char is a numeric character
   Return 1 if is a numeric char
   Return 0 if is something else */
int	is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

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
void	check_and_push(char **av, stack_head *a, stack_head *b)
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
			free_stacks(a, b);
			write(2, "Error\n", 6);
			exit(1);
		}
		push(a, tmp, i - 1);
	}
}
