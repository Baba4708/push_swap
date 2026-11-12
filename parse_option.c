/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbouvet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:30:51 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/12 15:30:56 by kbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	same_text(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (a[i] == b[i])
		return (1);
	return (0);
}

int	set_option(char *arg, t_config *config)
{
	if (!arg || !config)
		return (0);
	if (same_text(arg, "--simple"))
		config->strategy = SIMPLE;
	else if (same_text(arg, "--medium"))
		config->strategy = MEDIUM;
	else if (same_text(arg, "--complex"))
		config->strategy = COMPLEX;
	else if (same_text(arg, "--adaptive"))
		config->strategy = ADAPTIVE;
	else if (same_text(arg, "--bench"))
		config->bench = 1;
	else
		return (0);
	return (1);
}

int is_option(char *arg)
{
    if (!arg)
        return (0);
    if (same_text(arg, "--simple") || same_text(arg, "--medium"))
        return (1);
    if (same_text(arg, "--complex") || same_text(arg, "--adaptive"))
        return (1);
    if (same_text(arg, "--bench"))
        return (1);
    return (0);
}
