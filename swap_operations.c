/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:35:38 by bcili             #+#    #+#             */
/*   Updated: 2025/02/10 16:35:38 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_node **s_a)
{
    t_node  *temp;

    if (!(*s_a) || !((*s_a)->next))
        return ;
    temp = (*s_a)->next;
    (*s_a)->next = temp->next;
    temp->next = (*s_a);
    *s_a = temp;
    write (1, "sa\n", 3);
}

void    swap_b(t_node **s_b)
{
    t_node  *temp;

    if (!(*s_b) || !((*s_b)->next))
        return ;
    temp = (*s_b)->next;
    (*s_b)->next = temp->next;
    temp->next = (*s_b);
    *s_b = temp;
    write (1, "sb\n", 3);
}

void    swap_both(t_node **s_a, t_node **s_b)
{
    t_node  *temp;

    if (!(*s_a) || !((*s_a)->next) || !(*s_b) || ((*s_b)->next))
        return ;
    temp = (*s_a)->next;
    (*s_a)->next = temp->next;
    temp->next = (*s_a);
    *s_a = temp;
    temp = (*s_b)->next;
    (*s_b)->next = temp->next;
    temp->next = (*s_b);
    *s_b = temp;
    write (1, "ss\n", 3);
}
