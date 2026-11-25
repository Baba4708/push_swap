/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:06:39 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/25 12:25:32 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

static int	exe_operation(char *op, t_stack *a, t_stack *b)
{
	if (same_text(op, "pa\n"))
		pa(a, b);
	else if (same_text(op, "pb\n"))
		pb(a, b);
	else if (same_text(op, "sa\n"))
		s(a);
	else if (same_text(op, "sb\n"))
		s(b);
	else if (same_text(op, "ss\n"))
		ss(a, b);
	else if (same_text(op, "ra\n"))
		r(a);
	else if (same_text(op, "rb\n"))
		r(b);
	else if (same_text(op, "rr\n"))
		rr(a, b);
	else if (same_text(op, "rra\n"))
		revr(a);
	else if (same_text(op, "rrb\n"))
		revr(b);
	else if (same_text(op, "rrr\n"))
		revrr(a, b);
	else
		return (-1);
	return (0);
}

int	checker(t_stack *a, t_stack *b)
{
	char	*instruct;

	instruct = get_next_line(0);
	while (instruct != NULL)
	{
		if (exe_operation(instruct, a, b) == -1)
			return (-1);
		instruct = get_next_line(0);
	}
	if (compute_disorder(a) == 0 && b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(instruct);
	return (0);
}
