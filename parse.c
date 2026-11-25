/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:15:59 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/25 12:15:37 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char **argv, t_stack *a, t_config *config)
{
	int	count;

	a->array = NULL;
	a->size = 0;
	config->strategy = ADAPTIVE;
	config->bench = 0;
	config->disorder = 0;
	config->adaptive_method = 0;
	config->total_ops = 0;
	count = 0;
	while (count < 11)
	{
		config->counts[count] = 0;
		count++;
	}
	if (!count_values(argc, argv, &count, config))
		return (0);
	a->array = malloc(sizeof(int) * count);
	if (!a->array)
		return (0);
	if (!fill_stack(argc, argv, a, config) || has_duplicate(a))
		return (0);
	return (1);
}
