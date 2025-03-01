/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:13:16 by bcili             #+#    #+#             */
/*   Updated: 2025/03/01 14:07:55 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_index(t_node *node, int data)
{
	int		i;
	t_node	*temp;

	temp = node;
	i = 0;
	while (temp && temp->data != data)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

static void	sorter_push(t_stacks *stacks, int num_a, int num_b, char push_stack)
{
	int	index_a;
	int	index_b;
	int	len_a;
	int	len_b;

	len_a = stack_len(stacks->s_a);
	len_b = stack_len(stacks->s_b);
	if (stack_len(stacks->s_a) % 2 == 1)
		len_a = stack_len(stacks->s_a) + 1;
	if (stack_len(stacks->s_b) % 2 == 1)
		len_b = stack_len(stacks->s_b) + 1;
	index_a = calculate_index(stacks->s_a, num_a);
	index_b = calculate_index(stacks->s_b, num_b);
	if (len_a / 2 > index_a && len_b / 2 > index_b)
		plus_plus(stacks, num_a, num_b, push_stack);
	else if (len_a / 2 <= index_a && len_b / 2 > index_b)
		minus_plus(stacks, num_a, num_b, push_stack);
	else if (len_a / 2 > index_a && len_b / 2 <= index_b)
		plus_minus(stacks, num_a, num_b, push_stack);
	else if (len_a / 2 <= index_a && len_b / 2 <= index_b)
		minus_minus(stacks, num_a, num_b, push_stack);
}

static int	number_find_b(t_stacks *stacks, int data_a)
{
	int		min;
	int		max;
	int		count;
	t_node	*temp_b;

	count = 0;
	min = -2147483648;
	max = -2147483648;
	temp_b = stacks->s_b;
	while (temp_b)
	{
		if (temp_b->data < data_a && temp_b->data > min)
		{
			min = temp_b->data;
			count++;
		}
		else if (temp_b->data > data_a && temp_b->data > max)
			max = temp_b->data;
		temp_b = temp_b->next;
	}
	if (count > 0)
		return (min);
	return (max);
}

static int	number_a(t_stacks *stacks, int result_move, int result_num)
{
	int		move;
	int		num_b;
	int		index_a;
	int		index_b;
	t_node	*temp;

	temp = stacks->s_a;
	while (temp)
	{
		num_b = number_find_b(stacks, temp->data);
		index_a = calculate_index(stacks->s_a, temp->data);
		index_b = calculate_index(stacks->s_b, num_b);
		move = move_count(stacks, index_a, index_b, stack_len(stacks->s_a));
		if (move < result_move)
		{
			result_move = move;
			result_num = temp->data;
		}
		temp = temp->next;
	}
	return (result_num);
}

void	turkish_algorithm(t_stacks *stacks)
{
	int	num_a;
	int	num_b;

	num_a = 0;
	num_b = 0;
	push_b(&stacks->s_a, &stacks->s_b);
	if (stack_len(stacks->s_a) > 3)
	{
		push_b(&stacks->s_a, &stacks->s_b);
		while (stack_len(stacks->s_a) > 3)
		{
			num_a = number_a(stacks, 2147483647, 2147483647);
			num_b = number_find_b(stacks, num_a);
			sorter_push(stacks, num_a, num_b, 'b');
		}
		max_number_find_b(stacks, stacks->s_b->data);
	}
	sorting_for_three(&stacks->s_a);
	while (stacks->s_b)
	{
		num_a = number_find_a(stacks, stacks->s_b->data);
		sorter_push(stacks, num_a, stacks->s_b->data, 'a');
	}
	if (!is_sorted(&stacks->s_a))
		first_min_number_a(stacks, min_number_a(stacks));
}
