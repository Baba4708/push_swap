/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:08:44 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/12 14:21:01 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (a->size < 1)
		return ;
	b->size += 1;
	b->array[b->size - 1] = a->array[a->size - 1];
	a->size -= 1;
}

void	pb(t_stack *a, t_stack *b)
{
	if (b->size < 1)
		return ;
	a->size += 1;
	a->array[a->size - 1] = b->array[b->size - 1];
	b->size -= 1;
}
