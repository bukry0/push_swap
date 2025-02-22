/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:17:27 by bcili             #+#    #+#             */
/*   Updated: 2025/02/22 14:17:27 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_node **stack, int times, char stack_name)
{
	while (times > 0)
	{
		if (stack_name == 'a')
			rotate_a(stack);
		else
			rotate_b(stack);
		times--;
	}
}

static void	reverse_rotate_stack(t_node **stack, int times, char stack_name)
{
	while (times > 0)
	{
		if (stack_name == 'a')
			reverse_rotate_a(stack);
		else
			reverse_rotate_b(stack);
		times--;
	}
}

static void	rotate_to_position(t_node **stack, int pos, char stack_name)
{
	int	len;

	len = stack_len(*stack);
	if (pos <= len / 2)
		rotate_stack(stack, pos, stack_name);
	else
		reverse_rotate_stack(stack, len - pos, stack_name);
}

static int	find_min_pos(t_node *stack)
{
	t_node	*temp;
	int		min_pos;
	int		min_val;
	int		pos;

	temp = stack;
	min_val = temp->data;
	min_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->data < min_val)
		{
			min_val = temp->data;
			min_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (min_pos);
}

void	turkish_algorithm(t_stacks *stacks)
{
	int	len;
	int	min_pos;

	len = stack_len(stacks->s_a);
	while (len > 3)
	{
		min_pos = find_min_pos(stacks->s_a);
		rotate_to_position(&stacks->s_a, min_pos, 'a');
		push_b(&stacks->s_a, &stacks->s_b);
		len--;
	}
	sorting_for_three(&stacks->s_a);
	while (stacks->s_b)
		push_a(&stacks->s_a, &stacks->s_b);
}
