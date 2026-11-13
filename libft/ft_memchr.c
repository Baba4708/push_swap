/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:54:42 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/23 11:12:28 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	c_char;

	i = 0;
	c_char = c;
	temp = (unsigned char *)s;
	while (i < n)
	{
		if (temp[i] == c_char)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
