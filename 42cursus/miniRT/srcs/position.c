/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:31:03 by balee             #+#    #+#             */
/*   Updated: 2023/02/16 23:03:15 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

double	sphere_k(t_object *object, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	k;

	a = pow(ray.orient.x, 2) + pow(ray.orient.y, 2) + pow(ray.orient.z, 2);
	b = ray.orient.x * (ray.coord.x - object->coord.x)
		+ ray.orient.y * (ray.coord.y - object->coord.y)
		+ ray.orient.z * (ray.coord.z - object->coord.z);
	c = pow(ray.coord.x - object->coord.x, 2)
		+ pow(ray.coord.y - object->coord.y, 2)
		+ pow(ray.coord.z - object->coord.z, 2)
		- pow(((t_sphere *)object->info)->radius, 2);
	k = (-b - sqrt(pow(b, 2) - a * c)) / a;
	return (k);
}

double	plane_k(t_vec3 coord, t_vec3 normal, t_ray ray)
{
	double	k;

	k = ((coord.x - ray.coord.x) * normal.x
			+ (coord.y - ray.coord.y) * normal.y
			+ (coord.z - ray.coord.z) * normal.z)
		/ (ray.orient.x * normal.x + ray.orient.y * normal.y
			+ ray.orient.z * normal.z);
	return (k);
}

double	cylinder_k(t_object *object, t_ray ray)
{
	double		k1;
	double		k2;
	t_cylinder	*cyl;

	cyl = (t_cylinder *)object->info;
	if (vec3_inner_pd(ray.orient, cyl->normal) == 1
		|| vec3_inner_pd(ray.orient, cyl->normal) == -1)
		return (get_cylinder_k_base(object, ray));
	else if (vec3_inner_pd(ray.orient, cyl->normal) == 0)
		return (get_cylinder_k_side(object, ray));
	else
	{
		k1 = get_cylinder_k_base(object, ray);
		k2 = get_cylinder_k_side(object, ray);
	}
	if (k1 > k2 && k2 > 0)
		return (k2);
	return (k1);
}

double	get_k(t_object *object, t_ray ray)
{
	if (object->type == 'S')
		return (sphere_k(object, ray));
	else if (object->type == 'P')
		return (plane_k(object->coord, ((t_plane *)object->info)->normal, ray));
	else if (object->type == 'C')
		return (cylinder_k(object, ray));
	return (0);
}

t_vec3	get_pos(t_object *object, t_ray ray)
{
	t_vec3	pos;
	double	k;

	k = get_k(object, ray);
	pos.x = ray.coord.x + k * ray.orient.x;
	pos.y = ray.coord.y + k * ray.orient.y;
	pos.z = ray.coord.z + k * ray.orient.z;
	return (pos);
}
