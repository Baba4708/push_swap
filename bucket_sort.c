/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouvet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:36:24 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/13 14:36:26 by kbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	bucket_count(int size)
{
	int	count;

	count = 1;
	while (count * count < size)
		count++;
	return (count);
}

static void	move_bucket(t_stack *a, t_stack *b, long long low,
		long long high)
{
	int	i;
	int	limit;

	limit = a->size;
	i = 0;
	while (i < limit)
	{
		if ((long long)a->array[a->size - 1] >= low
			&& (long long)a->array[a->size - 1] <= high)
			tempo_pb(a, b);
		else
			tempo_ra(a);
		i++;
	}
}

static void	restore_stack(t_stack *a, t_stack *b)
{
	int	index;
	int	ra_count;
	int	rrb_count;

	while (b->size > 0)
	{
		index = bucket_max_index(b);
		ra_count = b->size - 1 - index;
		rrb_count = index + 1;
		if (ra_count <= rrb_count)
			while (ra_count-- > 0)
				tempo_rb(b);
		else
			while (rrb_count-- > 0)
				tempo_rrb(b);
		tempo_pa(a, b);
	}
}

void	bucket_sort(t_stack *a, t_stack *b)
{
	int			min;
	int			max;
	int			count;
	int			i;
	long long	width;

	if (a->size < 2)
		return ;
	min = bucket_min(a);
	max = bucket_max(a);
	count = bucket_count(a->size);
	width = ((long long)max - min + count) / count;
	i = 0;
	while (i < count && a->size > 0)
	{
		move_bucket(a, b, (long long)min + i * width,
			(long long)min + (i + 1) * width - 1);
		i++;
	}
	restore_stack(a, b);
}
