/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:12:41 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/24 13:26:15 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_arg(char type, va_list *args, size_t *count)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(*args, int), 1);
		(*count)++;
	}
	else if (type == 's')
		*count += ft_putstr_len(va_arg(*args, char *));
	else if (type == 'p')
		*count += ft_putptr_len(va_arg(*args, void *));
	else if (type == 'd' || type == 'i')
		*count += ft_putnbr_len(va_arg(*args, int));
	else if (type == 'u')
		*count += ft_unsigned_putnbr_len(va_arg(*args, unsigned int));
	else if (type == 'x')
		*count += ft_putnbr_hexa(va_arg(*args, unsigned int), 0);
	else if (type == 'X')
		*count += ft_putnbr_hexa(va_arg(*args, unsigned int), 1);
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	size_t	count;
	va_list	args;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			print_arg(str[++i], &args, &count);
		else
		{
			count++;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
