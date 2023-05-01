/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:33:16 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/01 10:03:36 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int *list, int size)
{
	int i, j, aux;
	i = 0;
	while (i < size - 1)
	{
		if (list[i] > list[i + 1])
		{
			aux = list[i + 1];
			list[i + 1] = list[i];
			list[i] = aux;
			j = i - 1;
			while (j >= 0)
			{
				if (aux < list[j])
				{
					list[j + 1] = list[j];
					list[j] = aux;
				}
				else
					break ;
				j--;
			}
		}
		i++;
	}
}
