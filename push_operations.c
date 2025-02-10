/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:08:03 by bcili             #+#    #+#             */
/*   Updated: 2025/02/10 22:08:03 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_node **s_a, t_node **s_b)
{
    t_node  *temp;

    if (!(*s_b))
        return ;
    temp = (*s_b)->next;
    (*s_b)->next = (*s_a);
    (*s_a) = (*s_b);
    (*s_b) = temp;
    write(1, "pa\n", 3);
}

void    push_b(t_node **s_a, t_node **s_b)
{
    t_node  *temp;

    if (!(*s_a))
        return ;
    temp = (*s_a)->next;
    (*s_a)->next = (*s_b);
    (*s_b) = (*s_a);
    (*s_a) = temp;
    write(1, "pb\n", 3);
}
