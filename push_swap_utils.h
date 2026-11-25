/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:40:01 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/25 12:21:54 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/ft_printf.h"

typedef struct s_stack
{
	int	*array;
	int	size;
}				t_stack;

typedef struct s_config
{
	int	strategy;
	int	bench;
	int	disorder;
	int	adaptive_method;
	int	counts[11];
	int	total_ops;
}				t_config;

typedef struct s_bucket
{
	int			min;
	int			max;
	int			count;
	int			index;
	long long	width;
	long long	range[2];
}			t_bucket;

void	s(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	r(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	revr(t_stack *stack);
void	revrr(t_stack *a, t_stack *b);

int		parse_number(char *str, int *value);
int		fill_arg(char *arg, t_stack *a);
int		same_text(char *a, char *b);
int		count_word(char *arg);
int		compute_disorder(t_stack *a);
int		has_duplicate(t_stack *a);

#endif
