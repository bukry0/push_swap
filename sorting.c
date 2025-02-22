/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:15:52 by bcili             #+#    #+#             */
/*   Updated: 2025/02/22 14:15:52 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node **stack)
{
	t_node	*temp;

	if (!stack || !(*stack))
		return (1);
	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	sort_three_case_one(t_node **s_a)
{
	swap_a(s_a);
	reverse_rotate_a(s_a);
}

static void	sort_three_elements(t_node **s_a, int a, int b, int c)
{
	if (a > b && b > c)
		sort_three_case_one(s_a);
	else if (a > b && a > c)
		rotate_a(s_a);
	else if (b > c)
		reverse_rotate_a(s_a);
}

void	sorting_for_three(t_node **s_a)
{
	int	a;
	int	b;
	int	c;

	if (!s_a || !(*s_a) || !(*s_a)->next)
		return ;
	if (!(*s_a)->next->next)
	{
		if (!s_a || !(*s_a) || !(*s_a)->next)
		    return ;
	    if ((*s_a)->data > (*s_a)->next->data)
		    swap_a(s_a);
		return ;
	}
	a = (*s_a)->data;
	b = (*s_a)->next->data;
	c = (*s_a)->next->next->data;
	sort_three_elements(s_a, a, b, c);
}

void	sorting(t_stacks *stacks)
{
	int	len;

	if (!stacks || !stacks->s_a)
		return ;
	if (is_sorted(&stacks->s_a))
		return ;
	len = stack_len(stacks->s_a);
	if (len == 2)
    {
	    if (stacks->s_a->data > stacks->s_a->next->data)
		    swap_a(&stacks->s_a);
    }
	else if (len == 3)
		sorting_for_three(&stacks->s_a);
	else
		turkish_algorithm(stacks);
}
