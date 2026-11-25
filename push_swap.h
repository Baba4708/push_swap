/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:24:04 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/25 12:18:01 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_utils.h"

# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define ADAPTIVE 4

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

int		parse_input(int argc, char **argv, t_stack *a, t_config *config);
int		count_values(int argc, char **argv, int *count, t_config *config);
int		fill_stack(int argc, char **argv, t_stack *a, t_config *config);
int		is_option(char *arg);
int		set_option(char *arg, t_config *config);
int		bucket_min(t_stack *a);
int		bucket_max(t_stack *a);
int		bucket_max_index(t_stack *b);
void	free_stacks(t_stack *a, t_stack *b);
void	tempo_pa(t_stack *a, t_stack *b, t_config *config);
void	tempo_pb(t_stack *a, t_stack *b, t_config *config);
void	tempo_ra(t_stack *a, t_config *config);
void	tempo_rb(t_stack *b, t_config *config);
void	tempo_rrb(t_stack *b, t_config *config);

void	insertion_sort(t_stack *a, t_stack *b, t_config *config);
void	bucket_sort(t_stack *a, t_stack *b, t_config *config);
void	bucket_sort(t_stack *a, t_stack *b, t_config *config);
int		radix_sort(t_stack *a, t_stack *b, t_config *config);
int		adaptive_sort(t_stack *a, t_stack *b, t_config *config);
int		compress_stack(t_stack *a);
void	bench_operation(t_config *config, int operation);
void	print_bench(t_config *config);

#endif
