/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:20:00 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/25 10:45:43 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*operation_name(int operation)
{
	if (operation == OP_SA)
		return ("sa\n");
	if (operation == OP_SB)
		return ("sb\n");
	if (operation == OP_SS)
		return ("ss\n");
	if (operation == OP_PA)
		return ("pa\n");
	if (operation == OP_PB)
		return ("pb\n");
	if (operation == OP_RA)
		return ("ra\n");
	if (operation == OP_RB)
		return ("rb\n");
	if (operation == OP_RR)
		return ("rr\n");
	if (operation == OP_RRA)
		return ("rra\n");
	if (operation == OP_RRB)
		return ("rrb\n");
	return ("rrr\n");
}

void	bench_operation(t_config *config, int operation)
{
	ft_putstr_fd(operation_name(operation), 1);
	config->counts[operation]++;
	config->total_ops++;
}

