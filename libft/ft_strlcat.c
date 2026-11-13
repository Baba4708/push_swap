/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:47:08 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/24 11:24:06 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendest;
	size_t	res;

	i = 0;
	lensrc = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (lensrc);
	lendest = ft_strlen(dest);
	if (lendest >= size)
		return (size + lensrc);
	res = lendest + lensrc;
	while (lendest + i < size - 1 && src[i] != '\0')
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (res);
}
