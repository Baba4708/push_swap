/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 10:47:02 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/24 11:04:23 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

static int	bonus_prepare_stacks(int argc, char **argv, t_stack *a)
{
	if (!bonus_parse_input(argc, argv, a))
	{
		write(2, "Error\n", 6);
		free(a->array);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;

	a.array = NULL;
	if (argc == 1)
		return (0);
	if (!bonus_prepare_stacks(argc, argv, &a))
		return (1);
	b.array = malloc(sizeof(int) * a.size);
	if (!b.array)
	{
		free(a.array);
		return (1);
	}
	b.size = 0;
	free_stacks(&a, &b);
	return (0);
}
