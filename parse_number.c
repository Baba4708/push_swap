/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:12:53 by kbouvet           #+#    #+#             */
/*   Updated: 2026/11/13 11:20:04 by bcaresme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	parse_number(char *str, int *value)
{
	long long	number;
	int			sign;
	int			i;

	number = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		number = number * 10 + str[i] - '0';
		if (number > 2147483648LL)
			return (0);
		i++;
	}
	number = number * sign;
	if (number < -2147483648LL || number > 2147483647LL)
		return (0);
	*value = (int)number;
	return (1);
}
