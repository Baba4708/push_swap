/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:35:54 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/13 14:43:31 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_word(char *arg, int *index, t_stack *a)
{
	char	saved;
	int		value;
	int		start;

	while (arg[*index] == ' ' || (arg[*index] >= 9 && arg[*index] <= 13))
		(*index)++;
	start = *index;
	while (arg[*index] && arg[*index] != ' '
		&& !(arg[*index] >= 9 && arg[*index] <= 13))
		(*index)++;
	if (start == *index)
		return (1);
	saved = arg[*index];
	arg[*index] = '\0';
	if (!parse_number(&arg[start], &value))
	{
		arg[*index] = saved;
		return (0);
	}
	arg[*index] = saved;
	a->array[a->size++] = value;
	return (1);
}

static int	fill_arg(char *arg, t_stack *a)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
			i++;
		if (arg[i] && !put_word(arg, &i, a))
			return (0);
	}
	return (1);
}

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
