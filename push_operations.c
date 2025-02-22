/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:12:25 by bcili             #+#    #+#             */
/*   Updated: 2025/02/22 14:12:25 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (!src || !(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	push_a(t_node **s_a, t_node **s_b)
{
	if (!s_b || !(*s_b))
		return ;
	push_node(s_a, s_b);
	if (!ft_write("pa\n"))
		return ;
}

void	push_b(t_node **s_a, t_node **s_b)
{
	if (!s_a || !(*s_a))
		return ;
	push_node(s_b, s_a);
	if (!ft_write("pb\n"))
		return ;
}
