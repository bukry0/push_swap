/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:13:37 by bcili             #+#    #+#             */
/*   Updated: 2025/02/22 14:13:37 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* Data Structures */
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stacks
{
	t_node	*s_a;
	t_node	*s_b;
}	t_stacks;

/* Stack Operations */
void		push_a(t_node **s_a, t_node **s_b);
void		push_b(t_node **s_a, t_node **s_b);
void		swap_a(t_node **s_a);
void		swap_b(t_node **s_b);
void		swap_both(t_node **s_a, t_node **s_b);
void		rotate_a(t_node **s_a);
void		rotate_b(t_node **s_b);
void		rotate_both(t_node **s_a, t_node **s_b);
void		reverse_rotate_a(t_node **s_a);
void		reverse_rotate_b(t_node **s_b);
void		reverse_rotate_both(t_node **s_a, t_node **s_b);

/* Memory Management */
void		free_node(t_node *node);
void		free_split(char **arr);
void		free_stack(t_node **stack);

/* String and Number Operations */
size_t		ft_strlen(const char *s);
long long	ft_atoi(char *str);
char		**ft_split(char const *s, char c);

/* Error Handling and Validation */
void		ft_error(void);
int			ft_isdigit(char *str);
int			error_check(char **argv, int argc);
int			ft_write(const char *str);

/* Stack Management */
t_node		*create_new_node(int data);
t_node		*transfer_to_list(char **argv, int argc, t_node **s_a);
int			stack_len(t_node *stack);
int			get_position(t_node *stack, t_node *node);

/* Sorting Algorithms */
void		sorting(t_stacks *stacks);
void		sorting_for_three(t_node **s_a);
void		turkish_algorithm(t_stacks *stacks);

#endif