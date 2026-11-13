/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouvet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:34:30 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/13 14:34:31 by kbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	tempo_pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		pb(a, b);
		write(1, "pa\n", 3);
	}
}

void	tempo_pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		pa(a, b);
		write(1, "pb\n", 3);
	}
}

void	tempo_ra(t_stack *a)
{
	if (a->size > 1)
	{
		r(a);
		write(1, "ra\n", 3);
	}
}

void	tempo_rb(t_stack *b)
{
	if (b->size > 1)
	{
		r(b);
		write(1, "rb\n", 3);
	}
}

void	tempo_rrb(t_stack *b)
{
	if (b->size > 1)
	{
		revr(b);
		write(1, "rrb\n", 4);
	}
}
