/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 10:55:18 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/24 11:00:14 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

int	bonus_fill_stack(int argc, char **argv, t_stack *a)
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
	return (1);
}

int	bonus_count_values(int argc, char **argv, int *count)
{
	int	i;

	i = 1;
	*count = 0;
	while (i < argc)
	{
		*count += count_word(argv[i]);
		i++;
	}
	return (*count > 0);
}

int	bonus_parse_input(int argc, char **argv, t_stack *a)
{
	int	count;

	a->array = NULL;
	a->size = 0;
	count = 0;
	if (!bonus_count_values(argc, argv, &count))
		return (0);
	a->array = malloc(sizeof(int) * count);
	if (!a->array)
		return (0);
	if (!bonus_fill_stack(argc, argv, a) || has_duplicate(a))
		return (0);
	return (1);
}
