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

void		add_terminal_node(t_node *node, t_node **s_a);
t_node  	*create_new_node(int data);
int			error_check(char **argv, int argc);
void		free_node(t_node *node);
void		free_split(char **a);
long long	ft_atoi(char *str);
void		ft_error(void);
int			ft_isdigit(char *str);
int			ft_isequal(char **argv, int i);
char		**ft_split(char const *s, char c);
int			ft_numcmp(char *s1, char *s2);
size_t		ft_strlen(const char *s);
void    	push_a(t_node **s_a, t_node **s_b);
void    	push_b(t_node **s_a, t_node **s_b);
void    	rotate_a(t_node **s_a);
void    	rotate_b(t_node **s_b);
void    	rotate_both(t_node **s_a, t_node **s_b);
void		swap_a(t_node **s_a);
void    	swap_b(t_node **s_b);
void    	swap_both(t_node **s_a, t_node **s_b);
t_node		*transfer_to_list(char **argv, int argc, t_node **s_a);

#endif