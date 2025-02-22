/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:07:54 by bcili             #+#    #+#             */
/*   Updated: 2025/02/22 16:07:54 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(long long result, int sign)
{
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return ((int)result);
}

static int	handle_sign(const char **str)
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
	sign = handle_sign((const char **)&str);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (check_overflow(result, sign));
}
