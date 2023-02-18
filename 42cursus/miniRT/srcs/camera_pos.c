/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:03:21 by balee             #+#    #+#             */
/*   Updated: 2023/02/18 22:41:42 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	check_camera_in_sphere(t_miniRT *minirt, t_object *obj, t_vec3 coord)
{
	double	d;

	d = vec3_norm(vec3_sub(obj->coord, coord));
	if (d <= ((t_sphere *)obj->info)->radius)
	{
		free_all(minirt);
		exit_err("Camera in sphere!");
	}
}

void	check_camera_in_plane(t_miniRT *minirt, t_object *obj, t_vec3 coord)
{
	t_plane	plane;

	plane = *(t_plane *)obj->info;
	if (vec3_inner_pd(plane.normal, vec3_sub(coord, obj->coord)) == 0)
	{
		free_all(minirt);
		exit_err("Camera in plane!");
	}
}

void	check_camera_in_cylinder(t_miniRT *minirt, t_object *obj, t_vec3 coord)
{
	double		d[2];
	t_vec3		pos;
	t_cylinder	cyl;

	cyl = *(t_cylinder *)obj->info;
	d[0] = vec3_norm(vec3_cross_pd(vec3_sub(coord, obj->coord),
				cyl.normal));
	pos = vec3_add(obj->coord, vec3_scalar_mul(cyl.height, cyl.normal));
	d[1] = vec3_norm(vec3_component_mul(cyl.normal,
				vec3_sub(coord, obj->coord)))
		+ vec3_norm(vec3_component_mul(cyl.normal, vec3_sub(coord, pos)));
	if (d[0] <= ((t_cylinder *)obj->info)->radius
		&& d[1] <= ((t_cylinder *)obj->info)->height)
	{
		free_all(minirt);
		exit_err("Camera in cylinder!");
	}
}

void	check_camera_pos(t_miniRT *minirt, t_camera camera, t_list *objs)
{
	t_object	*obj;

	while (objs != NULL)
	{
		obj = (t_object *)objs->content;
		if (obj->type == 'S')
			check_camera_in_sphere(minirt, obj, camera.coord);
		else if (obj->type == 'P')
			check_camera_in_plane(minirt, obj, camera.coord);
		else if (obj->type == 'C')
			check_camera_in_cylinder(minirt, obj, camera.coord);
		objs = objs->next;
	}
}
