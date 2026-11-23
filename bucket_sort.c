/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:36:24 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/23 11:38:51 by bcaresme         ###   ########.fr       */
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

static void	move_bucket(t_stack *a, t_stack *b, t_config *config,
		t_bucket *bucket)
{
	int	i;
	int	limit;

	limit = a->size;
	i = 0;
	while (i < limit)
	{
		if ((long long)a->array[a->size - 1] >= bucket->range[0]
			&& (long long)a->array[a->size - 1] <= bucket->range[1])
			tempo_pb(a, b, config);
		else
			tempo_ra(a, config);
		i++;
	}
}

static void	restore_stack(t_stack *a, t_stack *b, t_config *config)
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
				tempo_rb(b, config);
		else
			while (rrb_count-- > 0)
				tempo_rrb(b, config);
		tempo_pa(a, b, config);
	}
}

void	bucket_sort(t_stack *a, t_stack *b, t_config *config)
{
	t_bucket	bucket;

	if (a->size < 2)
		return ;
	bucket.min = bucket_min(a);
	bucket.max = bucket_max(a);
	bucket.count = bucket_count(a->size);
	bucket.width = ((long long)bucket.max - bucket.min
			+ bucket.count) / bucket.count;
	bucket.index = 0;
	while (bucket.index < bucket.count && a->size > 0)
	{
		bucket.range[0] = (long long)bucket.min + bucket.index * bucket.width;
		bucket.range[1] = (long long)bucket.min
			+ (bucket.index + 1) * bucket.width - 1;
		move_bucket(a, b, config, &bucket);
		bucket.index++;
	}
	restore_stack(a, b, config);
}
