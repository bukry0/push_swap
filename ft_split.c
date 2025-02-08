/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:51:54 by bcili             #+#    #+#             */
/*   Updated: 2025/02/04 18:57:38 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	ptr = (char *)malloc(len + 1);
	if ((ptr) == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\n';
	return (ptr);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) || (len + start) > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

static int	ft_count_word(const char *s, char c, char ***res, int *i)
{
	int	count_word;
	int	flag;

	count_word = 0;
	flag = 0;
	*i = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			flag = 1;
			count_word++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	*res = malloc(sizeof(char *) * (count_word + 1));
	return (count_word);
}

static int	free_node(char **str, int index)
{
	int	i;

	i = 0;
	if (!str[index - 1])
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (0);
	len = ft_count_word(s, c, &result, &i);
	if (!result)
		return (0);
	while (i < len)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] != c && s[j])
			j++;
		result[i++] = ft_substr(s, 0, j);
		if (free_node(result, i) == 0)
			return (0);
		s += j;
	}
	result[i] = 0;
	return (result);
}
