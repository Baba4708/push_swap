/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:24:17 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/24 11:08:14 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "bonus_push_swap.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	split_buf(char *buf, int start);
char	*split_stash(char *stash);
char	*ft_strjoin_gnl(char const *s1, char const *s2, int n);
char	*get_next_line(int fd);

#endif
