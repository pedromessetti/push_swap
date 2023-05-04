/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:26:12 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/04 15:41:00 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculates the length of the string pointed by s,
	excluding  the  terminating null byte ('\0') */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_mem(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static char	*ft_string(char const *s, char *new_s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	new_s = malloc(sizeof(char) * i + 1);
	if (!new_s || !s)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != c)
		new_s[i] = s[i];
	new_s[i] = '\0';
	return (new_s);
}

char	**ft_split(char const *s, char c)
{
	char	**new_s;
	int		i;
	int		j;

	new_s = (char **)malloc((ft_mem(s, c) + 1) * sizeof(char *));
	if (!new_s || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			new_s[j] = ft_string((char *)s + i, new_s[j], c);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	new_s[j] = 0;
	return (new_s);
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
	while (is_digit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}
