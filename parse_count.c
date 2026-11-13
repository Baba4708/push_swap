/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:27:54 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/13 11:12:44 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
			i++;
		if (arg[i])
			count++;
		while (arg[i] && arg[i] != ' ' && !(arg[i] >= 9 && arg[i] <= 13))
			i++;
	}
	return (count);
}

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
