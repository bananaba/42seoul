/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_log_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:44:50 by balee             #+#    #+#             */
/*   Updated: 2022/07/06 02:54:16 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*next_check(t_stack **log, t_stack *temp)
{
	t_stack	*next;

	if ((*log)->left == temp)
	{
		if (temp->left)
			temp->left->right = (*log)->right;
		if ((*log)->right)
			(*log)->right->left = temp->left;
		next = temp->left;
	}
	else
	{
		if (temp->left)
			temp->left->right = temp->right;
		if ((*log)->right)
			(*log)->right->left = (*log)->left;
		temp->right->left = temp->left;
		(*log)->left->right = (*log)->right;
		next = (*log)->left;
	}
	if ((*log)->right)
		next = (*log)->right;
	return (next);
}

t_stack	*check_swap2(t_stack **log)
{
	t_stack	*temp;
	t_stack	*next;

	temp = (*log)->left;
	next = temp;
	while (((*log)->data == 4
			&& (temp->data == 5 || temp->data == 10 || temp->data == 18))
		|| ((*log)->data == 5
			&& (temp->data == 4 || temp->data == 9 || temp->data == 17)))
		temp = temp->left;
	if (((*log)->data == 4 && temp->data == 4)
		|| ((*log)->data == 5 && temp->data == 5))
	{
		next = next_check(log, temp);
		free(*log);
		free(temp);
	}
	return (next);
}

t_stack	*check_rotation2(t_stack **log)
{
	t_stack	*temp;
	t_stack	*next;

	temp = (*log)->left;
	next = temp;
	while (((*log)->data == 10
			&& (temp->data == 4 || temp->data == 9 || temp->data == 17))
		|| ((*log)->data == 9
			&& (temp->data == 5 || temp->data == 10 || temp->data == 18)))
		temp = temp->left;
	if (((*log)->data == 9 && temp->data == 17)
		|| ((*log)->data == 10 && temp->data == 18))
	{
		next = next_check(log, temp);
		free(*log);
		free(temp);
	}
	return (next);
}

t_stack	*check_reverse_rotation2(t_stack **log)
{
	t_stack	*temp;
	t_stack	*next;

	temp = (*log)->left;
	next = temp;
	while (((*log)->data == 18
			&& (temp->data == 4 || temp->data == 9 || temp->data == 17))
		|| ((*log)->data == 17
			&& (temp->data == 5 || temp->data == 10 || temp->data == 18)))
		temp = temp->left;
	if (((*log)->data == 17 && temp->data == 9)
		|| ((*log)->data == 18 && temp->data == 10))
	{
		next = next_check(log, temp);
		free(*log);
		free(temp);
	}
	return (next);
}
