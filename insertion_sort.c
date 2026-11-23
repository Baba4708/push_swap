/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:08:50 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/23 16:05:33 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_max(int *min, int *max, t_stack *stack)
{
	int	i;

	i = 0;
	*min = 2147483647;
	*max = -2147483648;
	while (i < stack->size)
	{
		if (*min > stack->array[i])
			*min = stack->array[i];
		if (*max < stack->array[i])
			*max = stack->array[i];
		i++;
	}
}

static int	find_place(int nb, t_stack *stack)
{
	int	i;
	int	min;
	int	max;

	i = 0 ;
	find_min_max(&min, &max, stack);
	while (i < stack->size)
	{
		if (nb < min && stack->array[i] == min)
			return (i);
		if (nb > max && stack->array[i] == max)
			return (i + 1);
		if (stack->array[i] < nb && nb < stack->array[i + 1])
			return (i + 1);
		i++;
	}
	return (0);
}

static void	irotate(t_stack *b, int i, t_config *config)
{
	while (i != b->size)
	{
		if (i - b->size / 2 > 0)
		{
			r(b);
			bench_operation(config, OP_RB);
			i++;
		}
		else
		{
			if (i == 0)
				i = b->size;
			else
			{
				revr(b);
				bench_operation(config, OP_RRB);
				i--;
			}
		}
	}
}

static int	b_sorted(t_stack *b)
{
	int	i;
	int	j;
	int	mistakes;
	int	pairs;

	i = 0;
	mistakes = 0;
	pairs = 0;
	while (i < b->size)
	{
		j = i + 1;
		while (j < b->size)
		{
			pairs++;
			if (b->array[b->size - 1 - i] < b->array[b->size - 1 - j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (pairs == 0)
		return (0);
	return (mistakes * 10000 / pairs);
}

void	insertion_sort(t_stack *a, t_stack *b, t_config *config)
{
	int	i;

	pb(a, b);
	bench_operation(config, OP_PB);
	while (a->size > 0)
	{
		i = find_place(a->array[a->size - 1], b);
		irotate(b, i, config);
		pb(a, b);
		bench_operation(config, OP_PB);
	}
	while (b_sorted(b) != 0)
	{
		r(b);
		bench_operation(config, OP_RB);
	}
	while (b->size > 0)
	{
		pa(a, b);
		bench_operation(config, OP_PA);
	}
}
