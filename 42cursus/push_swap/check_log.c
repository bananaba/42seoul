/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:57:35 by balee             #+#    #+#             */
/*   Updated: 2022/07/05 16:42:01 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_swap1(t_stack **log)
{
	t_stack	*temp;
	t_stack	*next;

	temp = (*log)->left;
	next = temp;
	if (((*log)->data == 4 && temp->data == 5)
		|| ((*log)->data == 5 && temp->data == 4)
		|| ((*log)->data == 6 && (temp->data == 4 || temp->data == 5)))
	{
		if ((*log)->data == 6 && temp->data == 4)
			temp->data = 5;
		else if ((*log)->data == 6 && temp->data == 5)
			temp->data = 4;
		else
			temp->data = 6;
		(*log)->left->right = (*log)->right;
		if ((*log)->right)
			(*log)->right->left = (*log)->left;
		free(*log);
	}
	else
		next = check_swap2(log);
	*log = next;
}

void	check_push(t_stack **log)
{
	t_stack	*next1;
	t_stack	*next2;

	if (((*log)->data == 7 && (*log)->left->data == 8)
		|| ((*log)->data == 8 && (*log)->left->data == 7))
	{
		next1 = (*log)->right;
		next2 = (*log)->left->left;
		if (next2)
			next2->right = next1;
		if (next1)
			next1->left = next2;
		free((*log)->left);
		free(*log);
		if (next1)
			*log = next1;
		else
			*log = next2;
		return ;
	}
	*log = (*log)->left;
}

void	check_rotation1(t_stack **log)
{
	t_stack	*temp;
	t_stack	*next;

	temp = (*log)->left;
	next = temp;
	if (((*log)->data == 9 && temp->data == 10)
		|| ((*log)->data == 10 && temp->data == 9)
		|| ((*log)->data == 16 && (temp->data == 17 || temp->data == 18)))
	{
		if ((*log)->data == 16 && temp->data == 17)
			temp->data = 10;
		else if ((*log)->data == 16 && temp->data == 18)
			temp->data = 9;
		else
			temp->data = 16;
		(*log)->left->right = (*log)->right;
		if ((*log)->right)
			(*log)->right->left = (*log)->left;
		free(*log);
	}
	else
		next = check_rotation2(log);
	*log = next;
}

void	check_reverse_rotation1(t_stack **log)
{
	t_stack	*temp;
	t_stack	*next;

	temp = (*log)->left;
	next = temp;
	if (((*log)->data == 17 && temp->data == 18)
		|| ((*log)->data == 18 && temp->data == 17)
		|| ((*log)->data == 24 && (temp->data == 9 || temp->data == 10)))
	{
		if ((*log)->data == 24 && temp->data == 9)
			temp->data = 18;
		else if ((*log)->data == 24 && temp->data == 10)
			temp->data = 17;
		else
			temp->data = 24;
		(*log)->left->right = (*log)->right;
		if ((*log)->right)
			(*log)->right->left = (*log)->left;
		free(*log);
	}
	else
		next = check_reverse_rotation2(log);
	*log = next;
}

void	check_log(t_stack **log)
{
	while ((*log)->left)
	{
		if ((*log)->data == 4 || (*log)->data == 5 || (*log)->data == 6)
			check_swap1(log);
		else if ((*log)->data == 7 || (*log)->data == 8)
			check_push(log);
		else if ((*log)->data == 9 || (*log)->data == 10 || (*log)->data == 16)
			check_rotation1(log);
		else
			check_reverse_rotation1(log);
	}
}
