/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:39 by balee             #+#    #+#             */
/*   Updated: 2022/07/01 17:38:48 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# define MAX 2147483647
# define MIN -2147483648

typedef struct s_stack
{
	int				data;
	struct s_stack	*left;
	struct s_stack	*right;
}	t_stack;

typedef struct s_info
{
	t_stack	*a_top;
	t_stack	*a_bottom;
	t_stack	*b_top;
	t_stack	*b_bottom;
	int		a_factor;
	int		b_factor;
}	t_info;

typedef struct s_tree
{
	int				data;
	int				balance;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

int		push(t_info *info, int n, t_tree **node);
int		keep_arg(t_info *info, char *argv, t_tree **node);
int		add_input(t_tree **node, int input, t_info *info);
int		is_big(t_info *info, int pivot, int a);
int		is_small(t_info *info, int pivot, int b);
int		a_is_sorted(t_info *info, int a);
int		b_is_sorted(t_info *info, int b);
char	*rm_whitespace(char *argv);
void	ft_bzero(void *s, size_t n);
void	free_all(t_info *info);
void	free_all_t_tree(t_tree *node);
void	do_pa(t_info *info);
void	do_pb(t_info *info);
void	do_sa(t_info *info);
void	do_sb(t_info *info);
void	do_ra(t_info *info);
void	do_rb(t_info *info);
void	do_rra(t_info *info);
void	do_rrb(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
void	sort(t_info *info, int a, int b, t_tree *root);
void	sort_a_util1(t_info *info);
void	sort_b_util1(t_info *info);
void	sort_b_to_a(t_info *info, int trans, t_tree *root);
void	sort_a(t_info *info, int b, t_tree *root);
void	sort_b(t_info *info, int b);
void	sort4_a(t_info *info);
void	sort5_a(t_info *info);
void	sort6_a(t_info *info);
t_tree	*rotaterr(t_tree *node);
t_tree	*rotaterl(t_tree *node);
t_tree	*rotatell(t_tree *node);
t_tree	*rotatelr(t_tree *node);

#endif