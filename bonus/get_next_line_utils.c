/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 10:32:25 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/24 11:08:24 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	split_buf(char *buf, int start)
{
	int		i;

	i = 0;
	while (buf[i + start])
	{
		buf[i] = buf[i + start];
		i++;
	}
	buf[i] = '\0';
}

char	*split_stash(char *stash)
{
	int		i;
	char	*new;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	new = malloc(sizeof(char) * i + 1);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		new[i] = stash[i];
		i++;
	}
	new[i] = stash[i];
	if (stash[i] == '\n')
		new[++i] = '\0';
	free(stash);
	return (new);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2, int n)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*res;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc((len1 + len2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] && i < n)
	{
		res[i + len1] = s2[i];
		i++;
	}
	res[len1 + i] = '\0';
	free((void *)s1);
	return (res);
}
