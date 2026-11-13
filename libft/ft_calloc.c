/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:52:10 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/29 11:42:24 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			res;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	res = nmemb * size;
	ptr = malloc(res);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, res);
	return (ptr);
}
