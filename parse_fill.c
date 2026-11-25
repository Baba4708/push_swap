/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:35:54 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/25 12:14:47 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack(int argc, char **argv, t_stack *a, t_config *config)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < argc)
	{
		if (!is_option(argv[i]) && !fill_arg(argv[i], a))
			return (0);
		i++;
	}
	i = 0;
	j = a->size - 1;
	while (i < j)
	{
		temp = a->array[i];
		a->array[i] = a->array[j];
		a->array[j] = temp;
		i++;
		j--;
	}
	(void)config;
	return (1);
}
