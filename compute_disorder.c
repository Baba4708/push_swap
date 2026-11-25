/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:45:35 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/25 10:45:59 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	compute_disorder(t_stack *a)
{
	int	i;
	int	j;
	int	mistakes;
	int	pairs;

	i = 0;
	mistakes = 0;
	pairs = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			pairs++;
			if (a->array[a->size - 1 - i] > a->array[a->size - 1 - j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (pairs == 0)
		return (0);
	return (mistakes * 10000 / pairs);
}
