/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouvet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:20:00 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/17 16:20:00 by kbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	print_disorder(int disorder)
{
	char digit;

	ft_putstr_fd("[bench] Disorder: ", 2);
	ft_putnbr_fd(disorder / 100, 2);
	write(2, ".", 1);
	digit = '0' + disorder % 100 / 10;
	write(2, &digit, 1);
	digit = '0' + disorder % 10;
	write(2, &digit, 1);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(int strategy)
{
	ft_putstr_fd("[bench] Strategy: ", 2);
	if (strategy == SIMPLE)
		ft_putstr_fd("Simple (O(n^2))\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium - Bucket Sort (O(n*sqrt(n)))\n", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Complex (O(n log n))\n", 2);
	else
		ft_putstr_fd("Adaptive\n", 2);
}

static void	print_count(char *name, int count)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	write(2, "\n", 1);
}

void	print_bench(t_config *config)
{
	print_disorder(config->disorder);
	print_strategy(config->strategy);
	print_count("Total operations", config->total_ops);
	ft_putstr_fd("[bench] Operations breakdown:\n", 2);
	print_count("sa", config->counts[OP_SA]);
	print_count("sb", config->counts[OP_SB]);
	print_count("ss", config->counts[OP_SS]);
	print_count("pa", config->counts[OP_PA]);
	print_count("pb", config->counts[OP_PB]);
	print_count("ra", config->counts[OP_RA]);
	print_count("rb", config->counts[OP_RB]);
	print_count("rr", config->counts[OP_RR]);
	print_count("rra", config->counts[OP_RRA]);
	print_count("rrb", config->counts[OP_RRB]);
	print_count("rrr", config->counts[OP_RRR]);
}
