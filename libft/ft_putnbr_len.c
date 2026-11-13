/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:19:53 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/03 14:23:25 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int nb)
{
	int	len;

	ft_putnbr_fd(nb, 1);
	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
