/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 05:18:24 by balee             #+#    #+#             */
/*   Updated: 2022/06/30 05:23:02 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tree	*rotaterr(t_tree *node)
{
	t_tree	*root;

	root = node->right;
	node->right = root->left;
	root->left = node;
	return (root);
}

t_tree	*rotatell(t_tree *node)
{
	t_tree	*root;

	root = node->left;
	node->left = root->right;
	root->right = node;
	return (root);
}

t_tree	*rotaterl(t_tree *node)
{
	t_tree	*root;

	root = node->right->left;
	node->right->left = root->right;
	root->right = node->right;
	node->right = root->left;
	root->left = node;
	return (root);
}

t_tree	*rotatelr(t_tree *node)
{
	t_tree	*root;

	root = node->left->right;
	node->left->right = root->left;
	root->left = node->left;
	node->left = root->right;
	root->right = node;
	return (root);
}
