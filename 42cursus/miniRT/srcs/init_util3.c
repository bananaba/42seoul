/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:25:19 by balee             #+#    #+#             */
/*   Updated: 2023/02/13 22:43:49 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	malloc_info(t_miniRT *minirt, int type, t_object *obj)
{
	if (type == 0)
		obj->info = (t_sphere *)malloc(sizeof(t_sphere));
	else if (type == 1)
		obj->info = (t_plane *)malloc(sizeof(t_plane));
	else if (type == 2)
		obj->info = (t_cylinder *)malloc(sizeof(t_cylinder));
	else
		wrong_input(minirt);
}

t_object	*malloc_obj(t_miniRT *minirt, int type)
{
	t_list		*object;
	t_object	*obj;

	object = minirt->objects;
	while (object != NULL)
		object = object->next;
	object = (t_list *)malloc(sizeof(t_list));
	if (object == NULL)
		wrong_input(minirt);
	object->next = NULL;
	object->content = (t_object *)malloc(sizeof(t_object));
	if (object->content == NULL)
		wrong_input(minirt);
	obj = (t_object *)object->content;
	malloc_info(minirt, type, obj);
	return (obj);
}

void	get_objects(t_miniRT *minirt, char **str)
{
	if (ft_strncmp(*str, "sp", 2) == 0)
		get_sphere(minirt, str);
	else if (ft_strncmp(*str, "pl", 2) == 0)
		get_plane(minirt, str);
	else if (ft_strncmp(*str, "cy", 2) == 0)
		get_cylinder(minirt, str);
	else
		wrong_input(minirt);
}
