/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:21:21 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/09 15:25:42 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_line(char **stash, int fd, int reading)
{
	static char	buf[BUFFER_SIZE] = "";
	int			i;

	if (reading < BUFFER_SIZE)
		buf[reading] = '\0';
	i = 0;
	*stash = ft_strjoin_gnl(*stash, buf, reading);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		split_buf(buf, i + 1);
		return (0);
	}
	if (buf[reading] == '\0' && buf[0] != '\n')
		buf[0] = '\0';
	reading = read(fd, buf, BUFFER_SIZE);
	if (reading < 0)
		*stash[0] = '\0';
	return (reading);
}

char	*get_next_line(int fd)
{
	char		*stash;
	int			reading;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	stash = malloc(1);
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	reading = BUFFER_SIZE;
	while (reading > 0)
		reading = read_line(&stash, fd, reading);
	if (stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	stash = split_stash(stash);
	return (stash);
}
