/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:13:16 by bcili             #+#    #+#             */
/*   Updated: 2025/03/01 23:49:12 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// verilen datanın hangi düğümde olduğunu buluyor
int	find_index_of_data(t_node *node, int data)
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

// seçilen sayıların en üste nasıl hizalanacağını belirler
static void	choose_rotation_and_push(t_stacks *stacks, int num_a, int num_b, char push_stack)
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
	index_a = find_index_of_data(stacks->s_a, num_a);
	index_b = find_index_of_data(stacks->s_b, num_b);
	if (len_a / 2 > index_a && len_b / 2 > index_b)
		r_both_then_push(stacks, num_a, num_b, push_stack);
	else if (len_a / 2 <= index_a && len_b / 2 > index_b)
		rra_rb_then_push(stacks, num_a, num_b, push_stack);
	else if (len_a / 2 > index_a && len_b / 2 <= index_b)
		ra_rrb_then_push(stacks, num_a, num_b, push_stack);
	else if (len_a / 2 <= index_a && len_b / 2 <= index_b)
		rr_both_then_push(stacks, num_a, num_b, push_stack);
}

//data_a için b de olması gereken yeri buluyor
static int	find_best_fit_in_b(t_stacks *stacks, int data_a)
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

// b ye atmak için en uygun sayıyı buluyor
static int	find_best_to_push_to_b(t_stacks *stacks, int result_move, int result_num)
{
	int		move;
	int		num_b;
	int		index_a;
	int		index_b;
	t_node	*temp;

	temp = stacks->s_a;
	while (temp)
	{
		num_b = find_best_fit_in_b(stacks, temp->data);
		index_a = find_index_of_data(stacks->s_a, temp->data);
		index_b = find_index_of_data(stacks->s_b, num_b);
		move = calculate_move_cost(stacks, index_a, index_b, stack_len(stacks->s_a));
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
			num_a = find_best_to_push_to_b(stacks, 2147483647, 2147483647);
			num_b = find_best_fit_in_b(stacks, num_a);
			choose_rotation_and_push(stacks, num_a, num_b, 'b');
		}
		find_and_move_largest_in_b(stacks, stacks->s_b->data);
	}
	sorting_for_three(&stacks->s_a);
	while (stacks->s_b)
	{
		num_a = find_best_fit_in_a(stacks, stacks->s_b->data);
		choose_rotation_and_push(stacks, num_a, stacks->s_b->data, 'a');
	}
	if (!is_sorted(&stacks->s_a))
		move_min_to_top_a(stacks, find_min_in_a(stacks));
}
