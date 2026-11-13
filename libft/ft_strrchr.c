/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:55:54 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/23 11:11:06 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c_char;

	i = ft_strlen(s);
	c_char = c;
	while (i >= 0)
	{
		if (s[i] == c_char)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
