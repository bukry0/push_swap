/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:58:10 by bcili             #+#    #+#             */
/*   Updated: 2025/02/08 20:04:46 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	add_terminal_node(t_node *new_node, t_node **s_a)
{
	t_node	*root;

	root = *s_a;
	while ((*s_a)->next)
		(*s_a) = (*s_a)->next;
	(*s_a)->next = new_node;
	(*s_a) = root;
}
