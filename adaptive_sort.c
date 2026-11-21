/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouvet <marvin@42.fr>                     +#+  +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:00:00 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/20 16:00:00 by kbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	adaptive_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (config->disorder < 2000)
	{
		config->adaptive_method = SIMPLE;
		insertion_sort(a, b, config);
	}
	else if (config->disorder < 5000)
	{
		config->adaptive_method = MEDIUM;
		bucket_sort(a, b, config);
	}
	else
	{
		config->adaptive_method = COMPLEX;
		return (radix_sort(a, b, config));
	}
	return (1);
}
