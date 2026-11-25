/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 12:13:58 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/25 12:29:49 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

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

int	fill_arg(char *arg, t_stack *a)
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

int	has_duplicate(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->array[i] == a->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	same_text(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (a[i] == b[i])
		return (1);
	return (0);
}

int	count_word(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
			i++;
		if (arg[i])
			count++;
		while (arg[i] && arg[i] != ' ' && !(arg[i] >= 9 && arg[i] <= 13))
			i++;
	}
	return (count);
}
