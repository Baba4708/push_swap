/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:11:53 by bcaresme          #+#    #+#             */
/*   Updated: 2026/10/23 17:14:14 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnbdigit(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fillstr(char *str, int nbdigit, int isnegative, int n)
{
	if (isnegative)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[10] = '8';
			n /= 10;
			nbdigit--;
		}
		n *= -1;
	}
	while (nbdigit-- != 0)
	{
		str[nbdigit + isnegative] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		nbdigit;
	int		isnegative;

	nbdigit = getnbdigit(n);
	isnegative = 0;
	if (n <= 0)
		isnegative = 1;
	res = malloc((nbdigit + isnegative + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[nbdigit + isnegative] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	fillstr(res, nbdigit, isnegative, n);
	return (res);
}
