/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 10:47:02 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/25 10:39:13 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

static void	free_stacks(t_stack *a, t_stack *b)
{
	if (a->array)
		free(a->array);
	if (b->array)
		free(b->array);
}

static int	bonus_prepare_stacks(int argc, char **argv, t_stack *a)
{
	if (!bonus_parse_input(argc, argv, a))
	{
		ft_putendl_fd("Error", 1);
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
	if (checker(&a, &b) == -1)
		ft_putendl_fd("Error", 1);
	free_stacks(&a, &b);
	return (0);
}
