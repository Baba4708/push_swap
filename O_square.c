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

static void	bubble_a_to_b(t_stack *a, t_stack *b, int *count)
{
	while (a->size)
	{
		pb(a, b);
		ft_printf("pb\n");
		(*count)++;
		if (b->size > 1 && b->array[b->size - 1] < b->array[b->size - 2])
		{
			s(b);
			ft_printf("sb\n");
			(*count)++;
		}
	}
}

static int	bubble_b_to_a(t_stack *a, t_stack *b, int *count)
{
	int	did_swap;

	did_swap = 0;
	while (b->size)
	{
		pa(a, b);
		ft_printf("pa\n");
		(*count)++;
		if (a->size > 1 && a->array[a->size - 1] > a->array[a->size - 2])
		{
			s(a);
			ft_printf("sa\n");
			(*count)++;
			did_swap = 1;
		}
	}
	return (did_swap);
}

int	bubble_sort(t_stack *a, t_stack *b)
{
	int	count;
	int	did_swap;

	count = 0;
	did_swap = 1;
	while (did_swap)
	{
		bubble_a_to_b(a, b, &count);
		did_swap = bubble_b_to_a(a, b, &count);
	}
	return (count);
}
