/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:11:21 by bcili             #+#    #+#             */
/*   Updated: 2025/02/22 14:11:21 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

static void	add_node_to_stack(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!*stack)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

static int	process_number(char *str, t_node **stack)
{
	int		num;
	t_node	*new_node;

	num = (int)ft_atoi(str);
	if (num == 0 && str[0] != '0')
		return (0);
	new_node = create_new_node(num);
	if (!new_node)
		return (0);
	add_node_to_stack(stack, new_node);
	return (1);
}

static t_node	*process_split_args(char **args, t_node **stack)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!process_number(args[i], stack))
		{
			free_split(args);
			free_stack(stack);
			return (NULL);
		}
	}
	free_split(args);
	return (*stack);
}

t_node	*transfer_to_list(char **argv, int argc, t_node **stack)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
		return (process_split_args(args, stack));
	}
	i = 0;
	while (argv[++i])
	{
		if (!process_number(argv[i], stack))
		{
			free_stack(stack);
			return (NULL);
		}
	}
	return (*stack);
}
