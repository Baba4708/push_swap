/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:53:52 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/22 16:21:33 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		lenlittle;

	i = 0;
	lenlittle = ft_strlen(little);
	if (lenlittle > len)
		return (NULL);
	while (i + lenlittle <= len)
	{
		if (ft_strncmp(&big[i], little, lenlittle) == 0)
			return ((char *)&big[i]);
		if (!big[i])
			break ;
		i++;
	}
	return (NULL);
}
