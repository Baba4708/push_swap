/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:29:42 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/25 09:41:46 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_word(char const *s, char c, int start)
{
	int	i;

	i = start;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i - start);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

static void	freestrings(char **failed)
{
	int	i;

	i = 0;
	while (failed[i] != NULL)
	{
		free(failed[i]);
		i++;
	}
	free(failed);
}

static int	splitter(char const *s, char c, char **res, int i)
{
	int	j;
	int	lenword;

	j = 0;
	while (s[i] != '\0')
	{
		lenword = len_word(s, c, i);
		if (lenword == 0)
		{
			if (s[i] != c)
				j++;
			i++;
		}
		else
		{
			res[j] = ft_substr(s, i, lenword);
			if (res[j] == NULL)
				return (-1);
			j++;
		}
		i += lenword;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		nbwordgenerated;
	int		nbword;

	if (!s)
		return (NULL);
	i = 0;
	nbword = count_word(s, c);
	res = ft_calloc(nbword + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	nbwordgenerated = splitter(s, c, res, i);
	if (nbwordgenerated == -1)
	{
		freestrings(res);
		return (NULL);
	}
	res[nbwordgenerated] = NULL;
	return (res);
}
