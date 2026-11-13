/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:24:04 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/13 12:01:13 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
}				t_config;

# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define ADAPTIVE 4

int		parse_input(int argc, char **argv, t_stack *a, t_config *config);
int		count_values(int argc, char **argv, int *count, t_config *config);
int		fill_stack(int argc, char **argv, t_stack *a, t_config *config);
int		parse_number(char *str, int *value);
int		is_option(char *arg);
int		set_option(char *arg, t_config *config);
void	free_stacks(t_stack *a, t_stack *b);
void	write_error(void);
void	s(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	r(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	revr(t_stack *stack);
void	revrr(t_stack *a, t_stack *b);

int		bubble_sort(t_stack *a, t_stack *b);
void	tempo_medium(t_stack *a, t_stack *b);
void	tempo_complex(t_stack *a, t_stack *b);
void	tempo_adaptive(t_stack *a, t_stack *b);

#endif
