/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:27 by balee             #+#    #+#             */
/*   Updated: 2022/06/30 05:23:29 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	t_tree_height(t_tree *node)
{
	int	height_left;
	int	height_right;
	int	ret;

	height_left = 0;
	height_right = 0;
	if (!node)
		return (0);
	if (node->left)
		height_left = t_tree_height(node->left);
	if (node->right)
		height_right = t_tree_height(node->right);
	node->balance = height_left - height_right;
	if (height_left > height_right)
		ret = height_left + 1;
	else
		ret = height_right + 1;
	return (ret);
}

void	check_balance(t_tree **node)
{
	int	balance;

	if ((*node)->left)
		check_balance(&((*node)->left));
	if ((*node)->right)
		check_balance(&((*node)->right));
	balance = t_tree_height((*node)->left) - t_tree_height((*node)->right);
	if (balance >= 2)
	{
		if ((*node)->left->balance > 0)
			*node = rotatell(*node);
		else
			*node = rotatelr(*node);
	}
	else if (balance <= -2)
	{
		if ((*node)->right->balance > 0)
			*node = rotaterl(*node);
		else
			*node = rotaterr(*node);
	}
}

t_tree	*new_node(t_tree **node, int input)
{
	t_tree	*temp;

	temp = *node;
	while (*node)
	{
		if (input > temp->data && temp->right)
			temp = temp->right;
		else if (input > temp->data && !temp->right)
		{
			temp->right = (t_tree *)malloc(sizeof(t_tree));
			temp = temp->right;
			break ;
		}
		else if (input < temp->data && temp->left)
			temp = temp->left;
		else if (input < temp->data && !temp->left)
		{
			temp->left = (t_tree *)malloc(sizeof(t_tree));
			temp = temp->left;
			break ;
		}
		else
			return (0);
	}
	return (temp);
}

int	add_input(t_tree **node, int input, t_info *info)
{
	t_tree	*temp;

	temp = new_node(node, input);
	if (!temp && *node)
		return (0);
	if (!*node)
	{
		*node = (t_tree *)malloc(sizeof(t_tree));
		temp = *node;
	}
	(info->a_factor)++;
	temp->data = input;
	temp->balance = 0;
	temp->left = 0;
	temp->right = 0;
	check_balance(node);
	return (1);
}

void	free_all_t_tree(t_tree *node)
{
	if (node->left)
		free_all_t_tree(node->left);
	if (node->right)
		free_all_t_tree(node->right);
	free(node);
	node = 0;
}
