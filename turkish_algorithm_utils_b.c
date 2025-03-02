/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algorithm_utils_b.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:30:19 by bcili             #+#    #+#             */
/*   Updated: 2025/03/02 13:05:30 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_both_then_push(t_stacks *stacks, int n_a, int n_b, char push_stack)
{
	int	index_a;
	int	index_b;

	index_a = find_index_of_data(stacks->s_a, n_a);
	index_b = find_index_of_data(stacks->s_b, n_b);
	while (index_a > 0 && index_b > 0)
	{
		rotate_both(&stacks->s_a, &stacks->s_b);
		index_a--;
		index_b--;
	}
	while (index_b > 0)
	{
		rotate_b(&stacks->s_b);
		index_b--;
	}
	while (index_a > 0)
	{
		rotate_a(&stacks->s_a);
		index_a--;
	}
	if (push_stack == 'b')
		push_b(&stacks->s_a, &stacks->s_b);
	else
		push_a(&stacks->s_a, &stacks->s_b);
}

void	rra_rb_then_push(t_stacks *stacks, int n_a, int n_b, char push_stack)
{
	int	index_a;
	int	index_b;

	index_a = find_index_of_data(stacks->s_a, n_a);
	index_b = find_index_of_data(stacks->s_b, n_b);
	while (index_a < stack_len(stacks->s_a))
	{
		reverse_rotate_a(&stacks->s_a);
		index_a++;
	}
	while (index_b > 0)
	{
		rotate_b(&stacks->s_b);
		index_b--;
	}
	if (push_stack == 'b')
		push_b(&stacks->s_a, &stacks->s_b);
	else
		push_a(&stacks->s_a, &stacks->s_b);
}

void	ra_rrb_then_push(t_stacks *stacks, int n_a, int n_b, char push_stack)
{
	int	index_a;
	int	index_b;

	index_a = find_index_of_data(stacks->s_a, n_a);
	index_b = find_index_of_data(stacks->s_b, n_b);
	while (index_b < stack_len(stacks->s_b))
	{
		reverse_rotate_b(&stacks->s_b);
		index_b++;
	}
	while (index_a > 0)
	{
		rotate_a(&stacks->s_a);
		index_a--;
	}
	if (push_stack == 'b')
		push_b(&stacks->s_a, &stacks->s_b);
	else
		push_a(&stacks->s_a, &stacks->s_b);
}

void	rr_both_then_push(t_stacks *stacks, int n_a, int n_b, char push_stack)
{
	int	index_a;
	int	index_b;

	index_a = find_index_of_data(stacks->s_a, n_a);
	index_b = find_index_of_data(stacks->s_b, n_b);
	while (index_a < stack_len(stacks->s_a) && index_b < stack_len(stacks->s_b))
	{
		reverse_rotate_both(&stacks->s_a, &stacks->s_b);
		index_a++;
		index_b++;
	}
	while (index_a < stack_len(stacks->s_a))
	{
		reverse_rotate_a(&stacks->s_a);
		index_a++;
	}
	while (index_b < stack_len(stacks->s_b))
	{
		reverse_rotate_b(&stacks->s_b);
		index_b++;
	}
	if (push_stack == 'b')
		push_b(&stacks->s_a, &stacks->s_b);
	else
		push_a(&stacks->s_a, &stacks->s_b);
}
