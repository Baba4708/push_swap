/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:08:56 by bcaresme          #+#    #+#             */
/*   Updated: 2026/11/13 11:44:48 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr_hexa(unsigned long int nb, int isupper);
int	ft_putstr_len(char *str);
int	ft_putnbr_len(int nb);
int	ft_putptr_len(void *ptr);
int	ft_unsigned_putnbr_len(unsigned int nb);

#endif
