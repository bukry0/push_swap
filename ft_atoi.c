/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:07:54 by bcili             #+#    #+#             */
/*   Updated: 2025/02/28 16:42:49 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	check_overflow(long long result, int sign)
{
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
		return (-2147483649);
	return (result);
}

static int	handle_sign(char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

long long	ft_atoi(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = handle_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (check_overflow(result, sign) == -2147483649)
		{
			ft_error();
			exit(1);
		}
		str++;
	}
	return (result * sign);
}
