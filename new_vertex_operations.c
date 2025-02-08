/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vertex_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:58:10 by bcili             #+#    #+#             */
/*   Updated: 2025/02/08 20:04:46 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vertex	*create_new_vertex(int data)
{
	t_vertex	*new_vertex;

	new_vertex = (t_vertex *)malloc(sizeof(t_vertex));
	if (!new_vertex)
		return (NULL);
	new_vertex->data = data;
	new_vertex->next = NULL;
	return (new_vertex);
}

void	add_terminal_vertex(t_vertex *new_vertex, t_vertex **s_a)
{
	t_vertex	*start_point;

	start_point = *s_a;
	while (*s_a)
		(*s_a) = (*s_a)->next;
	(*s_a)->next = new_vertex;
	(*s_a) = start_point;
}
