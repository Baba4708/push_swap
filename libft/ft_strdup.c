/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:42:28 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/23 09:50:54 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dest;

	len = ft_strlen(src) + 1;
	dest = malloc(len * sizeof(char));
	if (dest == NULL)
		return (0);
	ft_strlcpy(dest, src, len);
	return (dest);
}
