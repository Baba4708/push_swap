/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   O_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:08:50 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/12 15:38:06 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_sort(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	while (a->size)
	{
		pa(a, b);
		count++;
		if (b->array[b->size - 1] < b->array[b->size - 2])
		{
			s(b);
			count++;
		}
	}
	while (b->size)
	{
		pb(a, b);
		count ++;
	}
	return (count);
}
