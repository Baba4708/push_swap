/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:00:00 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/23 15:49:59 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bit_count(int size)
{
	int	bits;
	int	value;

	bits = 0;
	value = size - 1;
	while (value > 0)
	{
		bits++;
		value /= 2;
	}
	return (bits);
}

static void	radix_pass(t_stack *a, t_stack *b, t_config *config, int bit)
{
	int	i;
	int	size;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((unsigned int)a->array[a->size - 1] >> bit) & 1u)
			tempo_ra(a, config);
		else
			tempo_pb(a, b, config);
		i++;
	}
	while (b->size > 0)
		tempo_pa(a, b, config);
}

int	radix_sort(t_stack *a, t_stack *b, t_config *config)
{
	int	bit;
	int	bits;

	if (a->size < 2)
		return (1);
	if (!compress_stack(a))
		return (0);
	bits = get_bit_count(a->size);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(a, b, config, bit);
		bit++;
	}
	return (1);
}
