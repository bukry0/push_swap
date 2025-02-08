/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:08:33 by bcili             #+#    #+#             */
/*   Updated: 2025/02/08 18:29:27 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '+' || *s2 == '+')
	{
		if (*s1 == '+' && *s2 != '+')
			s1++;
		else if (*s1 != '+' && *s2 == '+')
			s2++;
	}
	if ((ft_atoi(s1) == 0 && ft_atoi(s2) == 0) || ft_atoi(s1) > 2147483647
		|| ft_atoi(s2) > 2147483647 || ft_atoi(s1) < -2147483648
		|| ft_atoi(s2) < -2147483648)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_isequal(char **argv, int i)
{
	int	j;

	j = i;
	while (argv[++j])
	{
		if (!ft_strcmp(argv[i], argv[j]))
			return (0);
	}
	return (1);
}

int	error_check(char **argv, int argc)
{
	int		i;
	char	**a;

	if (argc == 2)
	{
		a = ft_split(argv[1], ' ');
		i = -1;
		while (a[++i])
		{
			if (!ft_isdigit(a[i]) || !ft_isequal(a, i))
				return (ft_error(), free_split(a), 0);
		}
		free_split(a);
	}
	i = 0;
	while (argv[++i] && argc != 2)
	{
		if (!ft_isdigit(argv[i]) || !ft_isequal(argv, i))
			return (ft_error(), 0);
	}
	return (1);
}
