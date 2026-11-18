/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   O_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:08:50 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/19 12:47:05 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *a, t_config *config)
{
	int	max;

	while (compute_disorder(a) != 0)
	{
		if (max < a->array[a->size - 1])
			max = a->array[a->size - 1];
		if (a->array[a->size - 1] > a->array[a->size - 2])
		{
			s(a);
			bench_operation(config, OP_SA);
			if (a->array[a->size - 1] == max)
			{
				r(a);
				bench_operation(config, OP_RA);
			}
		}
		else
		{
			r(a);
			bench_operation(config, OP_RA);
		}
		r(a);
		bench_operation(config, OP_RA);
	}
}
