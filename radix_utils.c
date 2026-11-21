/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouvet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:00:00 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/20 15:15:00 by kbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	copy_values(t_stack *a, int *values)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		values[i] = a->array[i];
		i++;
	}
}

static void	radix_insertion_sort(int *values, int size)
{
	int	i;
	int	j;
	int	current;

	i = 1;
	while (i < size)
	{
		current = values[i];
		j = i - 1;
		while (j >= 0 && values[j] > current)
		{
			values[j + 1] = values[j];
			j--;
		}
		values[j + 1] = current;
		i++;
	}
}

static int	find_rank(int *values, int size, int value)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (values[mid] == value)
			return (mid);
		if (values[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

int	compress_stack(t_stack *a)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * a->size);
	if (!sorted)
		return (0);
	copy_values(a, sorted);
	radix_insertion_sort(sorted, a->size);
	i = 0;
	while (i < a->size)
	{
		a->array[i] = find_rank(sorted, a->size, a->array[i]);
		i++;
	}
	free(sorted);
	return (1);
}
