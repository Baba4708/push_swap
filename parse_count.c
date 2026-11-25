/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:27:54 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/25 12:29:42 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_values(int argc, char **argv, int *count, t_config *config)
{
	int	i;

	i = 1;
	*count = 0;
	while (i < argc)
	{
		if (is_option(argv[i]))
			set_option(argv[i], config);
		else
			*count += count_word(argv[i]);
		i++;
	}
	return (*count > 0);
}
