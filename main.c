/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:54 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/13 11:23:53 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a->array)
		free(a->array);
	if (b->array)
		free(b->array);
}

static void	run_strategy(t_stack *a, t_stack *b, int strategy,
		t_config *config)
{
	if (strategy == SIMPLE)
		bubble_sort(a, b, config);
	else if (strategy == MEDIUM)
		bucket_sort(a, b, config);
	/*else if (strategy == COMPLEX)
		tempo_complex(a, b);
	else
		tempo_adaptive(a, b);*/
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	a.array = NULL;
	b.array = NULL;
	if (argc == 1)
		return (0);
	if (!parse_input(argc, argv, &a, &config))
	{
		write_error();
		free_stacks(&a, &b);
		return (1);
	}
	b.array = malloc(sizeof(int) * a.size);
	if (!b.array)
	{
		free_stacks(&a, &b);
		return (1);
	}
	b.size = 0;
	config.disorder = compute_disorder(&a);
	run_strategy(&a, &b, config.strategy, &config);
	if (config.bench)
		print_bench(&config);
	free_stacks(&a, &b);
	return (0);
}
