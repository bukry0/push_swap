/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:46:39 by bcili             #+#    #+#             */
/*   Updated: 2025/02/08 18:51:45 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_write(const char *str)
{
	ssize_t	len;
	ssize_t	ret;

	len = ft_strlen(str);
	ret = write(1, str, len);
	if (ret < 0 || ret != len)
		return (0);
	return (1);
}

void	ft_error(void)
{
	ft_write("Error\n");
}

static void	init_stacks(t_stacks **stacks)
{
	*stacks = malloc(sizeof(t_stacks));
	if (!(*stacks))
		return ;
	(*stacks)->s_a = NULL;
	(*stacks)->s_b = NULL;
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (!error_check(argv, argc))
		exit(EXIT_FAILURE);
	init_stacks(&stacks);
	if (!stacks)
		exit(EXIT_FAILURE);
	if (!transfer_to_list(argv, argc, &stacks->s_a))
	{
		free(stacks);
		free_stack(&stacks->s_a);
		exit(EXIT_FAILURE);
	}
	sorting(stacks);
	free_stack(&stacks->s_a);
	free_stack(&stacks->s_b);
	free(stacks);
	return (0);
}
