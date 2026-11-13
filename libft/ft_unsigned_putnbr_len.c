/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_len.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:22:20 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/03 13:20:59 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_unsigned_putnbr(unsigned int nb)
{
	char	unit;

	unit = 48 + nb % 10;
	if (nb > 9)
	{
		ft_unsigned_putnbr(nb / 10);
		ft_putchar_fd(unit, 1);
	}
	else
		ft_putchar_fd(unit, 1);
}

int	ft_unsigned_putnbr_len(unsigned int nb)
{
	int		len;

	ft_unsigned_putnbr(nb);
	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
