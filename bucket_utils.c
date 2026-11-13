/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouvet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:39:03 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/13 14:39:06 by kbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	bucket_min(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] < min)
			min = a->array[i];
		i++;
	}
	return (min);
}

int	bucket_max(t_stack *a)
{
	int	i;
	int	max;

	i = 0;
	max = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] > max)
			max = a->array[i];
		i++;
	}
	return (max);
}

int	bucket_max_index(t_stack *b)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < b->size)
	{
		if (b->array[i] > b->array[index])
			index = i;
		i++;
	}
	return (index);
}
