/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm_utils_a.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:39:11 by bcili             #+#    #+#             */
/*   Updated: 2025/03/02 13:05:12 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_fit_in_a(t_stacks *stacks, int data_b)
{
	int		max;
	int		min;
	t_node	*temp_a;
	int		count;

	temp_a = stacks->s_a;
	count = 0;
	max = 2147483647;
	min = 2147483647;
	while (temp_a)
	{
		if (temp_a->data > data_b && temp_a->data < max)
		{
			max = temp_a->data;
			count++;
		}
		else if (temp_a->data < data_b && temp_a->data < min)
			min = temp_a->data;
		temp_a = temp_a->next;
	}
	if (count > 0)
		return (max);
	return (min);
}

int	find_min_in_a(t_stacks *stacks)
{
	int		min;
	t_node	*temp;

	temp = stacks->s_a;
	min = 2147483647;
	while (temp)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

void	move_min_to_top_a(t_stacks *stacks, int data_a)
{
	int	index_a;

	index_a = find_index_of_data(stacks->s_a, data_a);
	if (stack_len(stacks->s_a) / 2 >= index_a)
	{
		while (index_a > 0)
		{
			rotate_a(&stacks->s_a);
			index_a--;
		}
	}
	index_a = find_index_of_data(stacks->s_a, data_a);
	if (stack_len(stacks->s_a) / 2 < index_a)
	{
		while (index_a < stack_len(stacks->s_a))
		{
			reverse_rotate_a(&stacks->s_a);
			index_a++;
		}
	}
}
