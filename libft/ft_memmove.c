/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:02:10 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/23 11:11:33 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*strsrc;
	unsigned char		*strdest;

	if (n == 0)
		return (dest);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	i = n;
	strsrc = (const unsigned char *)src;
	strdest = (unsigned char *)dest;
	while (i > 0)
	{
		i--;
		strdest[i] = strsrc[i];
	}
	return (dest);
}
