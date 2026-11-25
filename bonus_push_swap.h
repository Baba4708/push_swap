/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 10:50:39 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/25 12:27:07 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PUSH_SWAP_H
# define BONUS_PUSH_SWAP_H

# include "bonus_get_next_line.h"
# include "push_swap_utils.h"

int	bonus_parse_input(int argc, char **argv, t_stack *a);
int	checker(t_stack *a, t_stack *b);

#endif
