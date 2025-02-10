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

void    rotate_a(t_node **s_a)
{
    t_node  *iter;

    if (!(*s_a) || !((*s_a)->next))
        return ;
    iter = (*s_a);
    while (iter->next->next)
        iter = iter->next;
    iter->next->next = (*s_a);
    (*s_a) = iter->next;
    iter->next = NULL;
    write(1, "ra\n", 3);
}

void    rotate_b(t_node **s_b)
{
    t_node  *iter;

    if (!(*s_b) || !((*s_b)->next))
        return ;
    iter = (*s_b);
    while (iter->next->next)
        iter = iter->next;
    iter->next->next = (*s_b);
    (*s_b) = iter->next;
    iter->next = NULL;
    write(1, "rb\n", 3);
}

void    rotate_both(t_node **s_a, t_node **s_b)
{
    t_node  *iter;

    if (!(*s_a) || !((*s_a)->next) || !(*s_b) || !((*s_b)->next))
        return ;
    iter = (*s_a);
    while (iter->next->next)
        iter = iter->next;
    iter->next->next = (*s_a);
    (*s_a) = iter->next;
    iter->next = NULL;
    iter = (*s_b);
    while (iter->next->next)
        iter = iter->next;
    iter->next->next = (*s_b);
    (*s_b) = iter->next;
    iter->next = NULL;
    write(1, "rr\n", 3);
}
