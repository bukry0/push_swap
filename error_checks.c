/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:09:26 by bcili             #+#    #+#             */
/*   Updated: 2025/02/22 14:09:26 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_number_duplicate(char **argv, int i)
{
	int	j;

	j = i;
	while (argv[++j])
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			return (0);
	}
	return (1);
}

static int	validate_split_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!ft_isdigit(args[i]) || !check_number_duplicate(args, i))
			return (ft_error(), free_split(args), 0);
	}
	return (1);
}

int	error_check(char **argv, int argc)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (0);
		if (!validate_split_args(args))
			return (0);
		free_split(args);
		return (1);
	}
	i = 0;
	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]) || !check_number_duplicate(argv, i))
			return (ft_error(), 0);
	}
	return (1);
}
