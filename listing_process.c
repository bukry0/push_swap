/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:53 by bcili             #+#    #+#             */
/*   Updated: 2025/02/08 19:28:46 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

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
	return (sign * result);
}

static t_vertex	*for_more_than_two_argv(char **argv, t_vertex **s_a)
{
	t_vertex	*temp;
	t_vertex	*start_point;
	int			i;

	i = -1;
	while (argv[++i])
	{
		if (i == 0)
		{
			start_point = create_new_vertex(ft_atoi(argv[i]));
		}
		else
		{
			(*s_a)->data = ft_atoi(argv[i]);
			(*s_a)->next = temp;
			temp = *s_a;
		}
		*s_a = (*s_a)->next;
	}
	return (NULL);
}

static t_vertex	*for_two_argv(char **a, t_vertex **s_a)
{
	t_vertex	*new_vertex;
	t_vertex	*start_point;
	int			i;

	i = -1;
	start_point = NULL;
	while (a[++i])
	{
		if (i == 0)
		{
			*s_a = create_new_vertex(ft_atoi(a[i]));
			start_point = *s_a;
		}
		else
		{
			new_vertex->next = *s_a;
			*s_a = new_vertex;
		}
	}
	return (start_point);
}

t_vertex	*transfer_to_list(char **argv, int argc, t_vertex **s_a)
{
	char		**a;

	if (argc == 2)
	{
		a = ft_split(argv[1], ' ');
		return (for_two_argv(a, s_a));
	}
	else if (argc > 2)
		return (for_more_than_two_argv(argv + 1, s_a));
	return (NULL);
}
