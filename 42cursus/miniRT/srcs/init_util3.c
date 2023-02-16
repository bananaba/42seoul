/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:25:19 by balee             #+#    #+#             */
/*   Updated: 2023/02/14 18:47:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	malloc_info(t_miniRT *minirt, int type, t_object *obj, int fd)
{
	if (type == 0)
		obj->info = (t_sphere *)malloc(sizeof(t_sphere));
	else if (type == 1)
		obj->info = (t_plane *)malloc(sizeof(t_plane));
	else if (type == 2)
		obj->info = (t_cylinder *)malloc(sizeof(t_cylinder));
	else
		wrong_input(minirt, fd);
}

t_object	*malloc_obj(t_miniRT *minirt, int type, int fd)
{
	t_list		*object;
	t_object	*obj;

	object = (t_list *)malloc(sizeof(t_list));
	if (object == NULL)
		wrong_input(minirt, fd);
	if (minirt->objects == NULL)
		minirt->objects = object;
	else
		ft_lstadd_back(&minirt->objects, object);
	object->next = NULL;
	object->content = (t_object *)malloc(sizeof(t_object));
	if (object->content == NULL)
		wrong_input(minirt, fd);
	obj = (t_object *)object->content;
	malloc_info(minirt, type, obj, fd);
	return (obj);
}

void	get_objects(t_miniRT *minirt, int fd, char c1)
{
	char	c2;

	read(fd, &c2, 1);
	if (c1 == 's' && c2 == 'p')
		get_sphere(minirt, fd);
	else if (c1 == 'p' && c2 == 'l')
		get_plane(minirt, fd);
	else if (c1 == 'c' && c2 =='y')
		get_cylinder(minirt, fd);
	else
		wrong_input(minirt, fd);
}
