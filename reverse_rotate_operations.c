/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:14:39 by bcili             #+#    #+#             */
/*   Updated: 2025/02/22 14:14:39 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **s_a)
{
	t_node	*temp;
	t_node	*prev;

	if (!s_a || !(*s_a) || !(*s_a)->next)
		return ;
	prev = *s_a;
	while (prev->next->next)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	temp->next = *s_a;
	*s_a = temp;
	if (!ft_write("rra\n"))
		return ;
}

void	reverse_rotate_b(t_node **s_b)
{
	t_node	*temp;
	t_node	*prev;

	if (!s_b || !(*s_b) || !(*s_b)->next)
		return ;
	prev = *s_b;
	while (prev->next->next)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	temp->next = *s_b;
	*s_b = temp;
	if (!ft_write("rrb\n"))
		return ;
}

void	reverse_rotate_both(t_node **s_a, t_node **s_b)
{
	t_node	*temp;
	t_node	*prev;

	if (!s_a || !(*s_a) || !(*s_a)->next || !s_b || !(*s_b) || !(*s_b)->next)
		return ;
	prev = *s_a;
	while (prev->next->next)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	temp->next = *s_a;
	*s_a = temp;
	prev = *s_b;
	while (prev->next->next)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	temp->next = *s_b;
	*s_b = temp;
	if (!ft_write("rrr\n"))
		return ;
}
