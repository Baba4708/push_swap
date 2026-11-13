/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:27:09 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/25 11:25:36 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trimming_prep(char const *s1, char const *set, int *start)
{
	int	i;
	int	j;
	int	lenres;

	lenres = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && ft_strchr(&s1[i], set[j]) != &s1[i])
			j++;
		if (set[j] != '\0')
		{
			if (*start == i)
				*start = i + 1;
		}
		else
			lenres = i - (*start) + 1;
		i++;
	}
	return (lenres);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		lenres;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	lenres = trimming_prep(s1, set, &start);
	res = ft_substr(s1, start, lenres);
	return (res);
}
