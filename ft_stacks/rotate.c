/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:21:17 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/12 14:44:29 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size < 2)
		return ;
	i = 1;
	while (i < stack->size - 1)
	{
		tmp = stack->array[i];
		stack->array[i] = stack->array[i - 1];
		i++;
	}
	stack->array[0] = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	r(a);
	r(b);
}

void	revr(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size < 2)
		return ;
	i = stack->size - 2;
	while (i < 0)
	{
		tmp = stack->array[i];
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->size - 1] = tmp;
}

void	revrr(t_stack *a, t_stack *b)
{
	revr(a);
	revr(b);
}
