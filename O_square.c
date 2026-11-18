/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   O_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:08:50 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/15 12:05:54 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_a_to_b(t_stack *a, t_stack *b, int *count,
		t_config *config)
{
	while (a->size)
	{
		pb(a, b);
		bench_operation(config, OP_PB);
		(*count)++;
		if (b->size > 1 && b->array[b->size - 1] < b->array[b->size - 2])
		{
			s(b);
			bench_operation(config, OP_SB);
			(*count)++;
		}
	}
}

static int	bubble_b_to_a(t_stack *a, t_stack *b, int *count,
		t_config *config)
{
	int	did_swap;

	did_swap = 0;
	while (b->size)
	{
		pa(a, b);
		bench_operation(config, OP_PA);
		(*count)++;
		if (a->size > 1 && a->array[a->size - 1] > a->array[a->size - 2])
		{
			s(a);
			bench_operation(config, OP_SA);
			(*count)++;
			did_swap = 1;
		}
	}
	return (did_swap);
}

int	bubble_sort(t_stack *a, t_stack *b, t_config *config)
{
	int	count;
	int	did_swap;

	count = 0;
	did_swap = 1;
	while (did_swap)
	{
		bubble_a_to_b(a, b, &count, config);
		did_swap = bubble_b_to_a(a, b, &count, config);
	}
	return (count);
}
