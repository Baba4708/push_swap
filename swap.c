/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:46:32 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/12 15:09:21 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[stack->size - 1];
	stack->array[stack->size - 1] = stack->array[stack->size - 2];
	stack->array[stack->size - 2] = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	s(a);
	s(b);
}
