/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:30:34 by balee             #+#    #+#             */
/*   Updated: 2023/02/12 13:30:53 by balee            ###   ########.fr       */
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

t_vec3	get_normal(t_object *object, t_vec3 pos, t_ray ray)
{
	if (object->type == 'S')
		return (sphere_normal(object, pos));
	else if (object->type == 'P')
		return (plane_normal(object, ray));
}
