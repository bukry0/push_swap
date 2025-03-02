/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:48:37 by bcili             #+#    #+#             */
/*   Updated: 2025/02/08 19:08:20 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

void		push_a(t_node **s_a, t_node **s_b);
void		push_b(t_node **s_a, t_node **s_b);
void		reverse_rotate_a(t_node **s_a);
void		reverse_rotate_b(t_node **s_b);
void		reverse_rotate_both(t_node **s_a, t_node **s_b);
void		rotate_a(t_node **s_a);
void		rotate_b(t_node **s_b);
void		rotate_both(t_node **s_a, t_node **s_b);
void		swap_a(t_node **s_a);
void		swap_b(t_node **s_b);
void		swap_both(t_node **s_a, t_node **s_b);

void		free_node(t_node *node);
void		free_split(char **arr);
void		free_stack(t_node **stack);

long long	ft_atoi(char *str);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);

int			error_check(char **argv, int argc);
void		ft_error(void);
int			ft_write(const char *str);

t_node		*create_new_node(int data);
int			is_sorted(t_node **stack);
int			stack_len(t_node *stack);
t_node		*transfer_to_list(char **argv, int argc, t_node **s_a);

int			calculate_move_cost(t_stacks *stk, int inx_a, int inx_b, int len_a);
void		find_and_move_largest_in_b(t_stacks *stacks, int data_b);
int			find_best_fit_in_a(t_stacks *stacks, int data_b);
int			find_index_of_data(t_node *node, int data);
int			find_min_in_a(t_stacks *stacks);
void		move_min_to_top_a(t_stacks *stacks, int data_a);
void		r_both_then_push(t_stacks *stk, int nm_a, int nm_b, char push_stk);
void		ra_rrb_then_push(t_stacks *stk, int nm_a, int nm_b, char push_stk);
void		rr_both_then_push(t_stacks *stk, int nm_a, int nm_b, char push_stk);
void		rra_rb_then_push(t_stacks *stk, int nm_a, int nm_b, char push_stk);
void		sorting(t_stacks *stacks);
void		sorting_for_three(t_node **s_a);
void		turkish_algorithm(t_stacks *stacks);

#endif