/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:30:33 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/22 16:58:52 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	res;
	char	c;

	i = 0;
	res = ft_strlen(src);
	if (size)
	{
		while (i < size - 1)
		{
			c = src[i];
			dst[i] = c;
			if (c == '\0')
				return (res);
			i ++;
		}
		dst[i] = '\0';
	}
	return (res);
}
