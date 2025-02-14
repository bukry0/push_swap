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
#include <stdio.h>

void    swap_a(t_node **s_a, int i)
{
    t_node	*iter1;
    t_node  *iter2;
	t_node	*temp;

	if (!(*s_a) || !((*s_a)->next))
        return ;
    iter1 = *s_a;
	while (iter1->next->next)
        iter1 = iter1->next;
    temp = iter1->next;
	iter1->next = NULL;
	temp->next = iter1;
	if (*s_a == iter1)
        *s_a = temp;
	else
	{
        iter2 = *s_a;
        while (iter2->next != iter1)
        {
            iter2 = iter2->next;
        }
		iter2->next = temp;
	}
    if (i == 1)
        write (1, "sa\n", 3);
}

void    swap_b(t_node **s_b, int i)
{
    t_node	*iter1;
    t_node  *iter2;
	t_node	*temp;

	if (!(*s_b) || !((*s_b)->next))
		return ;
	iter1 = *s_b;
	while (iter1->next->next)
		iter1 = iter1->next;
	temp = iter1->next;
	iter1->next = NULL;
	temp->next = iter1;
	if (*s_b == iter1)
		*s_b = temp;
	else
	{
        iter2 = *s_b;
		while (iter2->next != iter1)
			iter2 = iter2->next;
		iter2->next = temp;
	}
    if (i == 1)
        write (1, "sa\n", 3);
}

void    swap_both(t_node **s_a, t_node **s_b)
{
    swap_a(s_a, 0);
    swap_b(s_b, 0);
    write(1, "ss\n", 3);
}
