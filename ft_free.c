/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:43:20 by bcili             #+#    #+#             */
/*   Updated: 2025/02/05 15:47:59 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **a)
{
	int	i;

	i = -1;
	while (a[++i])
		free(a[i]);
	free(a);
}

void	free_node(t_node *node)
{
	if (!node)
		return ;
	node->data = 0;
	free(node);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}	
}
