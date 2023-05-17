/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:26:12 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/17 22:56:17 by pedro            ###   ########.fr       */
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

/*Allocate NMEMB elements of SIZE bytes each, all initialized to 0.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc_space;

	alloc_space = (void *)malloc(nmemb * size);
	if (!alloc_space)
		return (NULL);
	ft_memset(alloc_space, 0, (nmemb * size));
	return (alloc_space);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
