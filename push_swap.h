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

typedef struct s_vertex
{
	int				data;
	struct s_vertex	*next;
}	t_vertex;

typedef struct s_stacks
{
	t_vertex	*s_a;
	t_vertex	*s_b;
}	t_stacks;

void		add_terminal_vertex(t_vertex *node, t_vertex **s_a);
t_vertex	*create_new_vertex(int data);
int			error_check(char **argv, int argc);
void		free_split(char **a);
int			ft_atoi(char *str);
void		ft_error(void);
int			ft_isdigit(char *str);
int			ft_isequal(char **argv, int i);
char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlen(const char *s);
t_vertex	*transfer_to_list(char **argv, int argc, t_vertex **s_a);

#endif