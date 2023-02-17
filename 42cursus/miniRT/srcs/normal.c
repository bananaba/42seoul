/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:30:34 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 15:28:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	sphere_normal(t_object *object, t_vec3 pos)
{
	t_vec3	normal;

	normal = vec3_sub(pos, object->coord);
	normal = vec3_normal(normal);
	return (normal);
}

t_vec3	plane_normal(t_object *object, t_ray ray)
{
	t_vec3	normal;

	normal = ((t_plane *)object->info)->normal;
	if (vec3_inner_pd(ray.orient, normal) >= 0)
	normal = vec3_scalar_mul(-1, normal);
	normal = vec3_normal(normal);
	return (normal);
}

t_vec3	cylinder_normal(t_object *obj, t_vec3 pos, t_ray ray)
{
	t_vec3	normal;
	t_vec3	proj;
	double	k;

	k = get_cylinder_k_base(obj, ray);
	normal = ((t_cylinder *)obj->info)->normal;
	if (k > 0)
	{
		if (vec3_inner_pd(ray.orient, normal) >= 0)
			normal = vec3_scalar_mul(-1, normal);
	}
	else
	{
		proj = vec3_add(obj->coord, vec3_scalar_mul(\
			vec3_inner_pd(vec3_sub(pos, obj->coord), normal), normal));
		normal = vec3_normal(vec3_sub(pos, proj));
	}
	return (normal);
}

t_vec3	get_normal(t_object *object, t_vec3 pos, t_ray ray)
{
	if (object->type == 'S')
		return (sphere_normal(object, pos));
	else if (object->type == 'P')
		return (plane_normal(object, ray));
	else if (object->type == 'C')
		return (cylinder_normal(object, pos, ray));
	return ((t_vec3){0, 0, 1});
}
