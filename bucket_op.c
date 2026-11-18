/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:34:30 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/14 15:13:59 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tempo_pa(t_stack *a, t_stack *b, t_config *config)
{
	if (b->size > 0)
	{
		pa(a, b);
		bench_operation(config, OP_PA);
	}
}

void	tempo_pb(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size > 0)
	{
		pb(a, b);
		bench_operation(config, OP_PB);
	}
}

void	tempo_ra(t_stack *a, t_config *config)
{
	if (a->size > 1)
	{
		r(a);
		bench_operation(config, OP_RA);
	}
}

void	tempo_rb(t_stack *b, t_config *config)
{
	if (b->size > 1)
	{
		r(b);
		bench_operation(config, OP_RB);
	}
}

void	tempo_rrb(t_stack *b, t_config *config)
{
	if (b->size > 1)
	{
		revr(b);
		bench_operation(config, OP_RRB);
	}
}
