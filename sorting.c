/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:11:21 by bcili             #+#    #+#             */
/*   Updated: 2025/03/01 12:34:22 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **stack)
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

void	sorting_for_three(t_node **s_a)
{
	int	first;
	int	second;
	int	third;

	first = (*s_a)->data;
	second = (*s_a)->next->data;
	third = (*s_a)->next->next->data;
	if (is_sorted(s_a))
		return ;
	if (first < second && second > third && first < third)
	{
		reverse_rotate_a(s_a);
		swap_a(s_a);
	}
	else if (first > second && second < third && first < third)
		swap_a(s_a);
	else if (first < second && second > third && first > third)
		reverse_rotate_a(s_a);
	else if (first > second && second < third && first > third)
		rotate_a(s_a);
	else if (first > second && second > third && first > third)
	{
		rotate_a(s_a);
		swap_a(s_a);
	}
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
