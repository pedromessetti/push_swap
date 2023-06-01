/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:26:12 by pmessett          #+#    #+#             */
/*   Updated: 2023/06/01 11:36:51 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculates the length of the string pointed by s,
	excluding  the  terminating null byte ('\0') */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

/* Converts the string pointed by nptr to an int 
	Return the string converted to int */
long	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_is_digit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

/* Check if there is a numeric character in the string pointed by s
   Return 1 if the string is a numeric char
   Return 0 if find something else */
int	ft_str_is_num(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] == 45 && ft_is_digit(s[1]))
		i++;
	while (s[i])
	{
		if (!ft_is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Check if the char is a numeric character
   Return 1 if is a numeric char
   Return 0 if is something else */
int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
