/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:15:35 by bcili             #+#    #+#             */
/*   Updated: 2025/03/01 14:15:06 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

static void	max_number_top_b(t_stacks *stacks, int max_index)
{
	if (stack_len(stacks->s_b) / 2 > max_index)
	{
		while (max_index > 0)
		{
			rotate_b(&stacks->s_b);
			max_index--;
		}
	}
	else if (stack_len(stacks->s_b) / 2 < max_index)
	{
		while (max_index < stack_len(stacks->s_b))
		{
			reverse_rotate_b(&stacks->s_b);
			max_index++;
		}
	}
}

void	max_number_find_b(t_stacks *stacks, int data_b)
{
	int		max;
	int		max_index;
	t_node	*temp_b;

	max = -2147483648;
	temp_b = stacks->s_b;
	while (temp_b)
	{
		if (temp_b->data > data_b && temp_b->data > max)
			max = temp_b->data;
		temp_b = temp_b->next;
	}
	max_index = calculate_index(stacks->s_b, max);
	max_number_top_b(stacks, max_index);
}

int	move_count(t_stacks *stacks, int index_a, int index_b, int len_a)
{
	int	len_b;

	len_b = stack_len(stacks->s_b);
	if (stack_len(stacks->s_a) % 2 == 1)
		len_a = stack_len(stacks->s_a) + 1;
	if (stack_len(stacks->s_b) % 2 == 1)
		len_b = stack_len(stacks->s_b) + 1;
	if (len_a / 2 > index_a && len_b / 2 > index_b)
	{
		if (index_a >= index_b)
			return (index_a);
		return (index_b);
	}
	else if (len_a / 2 <= index_a && len_b / 2 > index_b)
		return (((index_a - stack_len(stacks->s_a)) * (-1)) + index_b);
	else if (len_a / 2 > index_a && len_b / 2 <= index_b)
		return (((index_b - stack_len(stacks->s_b)) * (-1)) + index_a);
	else if (len_a / 2 <= index_a && len_b / 2 <= index_b)
	{
		if (stack_len(stacks->s_a) - index_a > stack_len(stacks->s_b) - index_b)
			return ((index_a - stack_len(stacks->s_a)) * (-1));
		return ((index_b - stack_len(stacks->s_b)) * (-1));
	}
	return (0);
}
