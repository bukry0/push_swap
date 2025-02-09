/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:53 by bcili             #+#    #+#             */
/*   Updated: 2025/02/08 20:05:29 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(char *str)
{
	long long	result;
	int 		sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	result = sign * result;
	if (result < -2147483648 || result > 2147483647)
		return (-2147483649);
	return (result);
}

static t_node	*transfer_operation(char **a, t_node **s_a)
{
	t_node	*new_node;
	int		i;

	i = -1;
	while (a[++i])
	{
		if (i == 0)
			*s_a = create_new_node(ft_atoi(a[i]));
		else
		{
			new_node = create_new_node(ft_atoi(a[i]));
			add_terminal_node(new_node, s_a);
		}
	}
	return (*s_a);
}

t_node	*transfer_to_list(char **argv, int argc, t_node **s_a)
{
	char    **a;

	if (argc == 2)
	{
		a = ft_split(argv[1], ' ');
		return (transfer_operation(a, s_a));
	}
	else if (argc > 2)
		return (transfer_operation(argv + 1, s_a));
	return (NULL);
}
