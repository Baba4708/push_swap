/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:17:03 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/03 14:23:05 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long int nb, int isupper)
{
	char	*base;
	int		count;

	count = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (isupper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb / 16 != 0)
		count += ft_putnbr_hexa(nb / 16, isupper) + 1;
	else
		count++;
	ft_putchar_fd(base[nb % 16], 1);
	return (count);
}
