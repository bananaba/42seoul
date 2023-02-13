/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:00:10 by balee             #+#    #+#             */
/*   Updated: 2023/02/13 18:51:26 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	exit_err(void)
{
	perror("Error");
	exit(1);
}

void	free_all(t_miniRT *minirt)
{
	t_list	*temp;

	while (minirt->lights != NULL)
	{
		temp = minirt->lights;
		if (temp->content != NULL)
			free(temp->content);
		temp = temp->next;
		free(minirt->lights);
		minirt->lights = temp;
	}
	while (minirt->objects != NULL)
	{
		temp = minirt->objects;
		if (temp->content != NULL)
		{
			if (((t_object *)temp->content)->info != NULL)
				free(((t_object *)temp->content)->info);
			free(temp->content);
		}
		temp = temp->next;
		free(minirt->objects);
		minirt->objects = temp;
	}
}

int	destroy_notify(t_miniRT *minirt)
{
	mlx_destroy_window(minirt->mlx, minirt->win);
	free_all(minirt);
	exit(0);
}
