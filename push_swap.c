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
#include <stdio.h>

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_node		*root;
	t_node		*temp;
	
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (ft_error(), 0);
	if (argc < 2)
		return (ft_error(), 0);
	if (!error_check(argv, argc))
		return (0);
	
	stacks->s_a = transfer_to_list(argv, argc, &stacks->s_a);
	root = stacks->s_a;
	temp = stacks->s_a;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	free_stack(&root);
	free(stacks);
}

