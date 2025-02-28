/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:58:19 by bcili             #+#    #+#             */
/*   Updated: 2025/02/10 22:58:19 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **s_a)
{
	t_node	*temp;
	t_node	*last;

	if (!s_a || !(*s_a) || !(*s_a)->next)
		return ;
	temp = *s_a;
	last = *s_a;
	while (last->next)
		last = last->next;
	*s_a = (*s_a)->next;
	temp->next = NULL;
	last->next = temp;
	if (!ft_write("ra\n"))
		return ;
}

void	rotate_b(t_node **s_b)
{
	t_node	*temp;
	t_node	*last;

	if (!s_b || !(*s_b) || !(*s_b)->next)
		return ;
	temp = *s_b;
	last = *s_b;
	while (last->next)
		last = last->next;
	*s_b = (*s_b)->next;
	temp->next = NULL;
	last->next = temp;
	if (!ft_write("rb\n"))
		return ;
}

void	rotate_both(t_node **s_a, t_node **s_b)
{
	t_node	*temp;
	t_node	*last;

	if (!s_a || !(*s_a) || !(*s_a)->next || !s_b || !(*s_b) || !(*s_b)->next)
		return ;
	temp = *s_a;
	last = *s_a;
	while (last->next)
		last = last->next;
	*s_a = (*s_a)->next;
	temp->next = NULL;
	last->next = temp;
	temp = *s_b;
	last = *s_b;
	while (last->next)
		last = last->next;
	*s_b = (*s_b)->next;
	temp->next = NULL;
	last->next = temp;
	if (!ft_write("rr\n"))
		return ;
}
