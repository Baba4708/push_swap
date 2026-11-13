/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:21:33 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/03 14:23:22 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_len(void *ptr)
{
	int	count;

	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	count = 2;
	ft_putstr_fd("0x", 1);
	count += ft_putnbr_hexa((unsigned long int)ptr, 0);
	return (count);
}
