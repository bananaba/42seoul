/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_util1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:08:13 by balee             #+#    #+#             */
/*   Updated: 2023/02/16 23:18:49 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

double	get_cylinder_k_base(t_object *obj, t_ray ray)
{
	double		k1;
	double		k2;
	t_vec3		coord;
	t_cylinder	cyl;

	cyl = *(t_cylinder *)obj->info;
	if (vec3_inner_pd(cyl.normal, ray.orient) == 0)
		return (0);
	k1 = plane_k(obj->coord, cyl.normal, ray);
	coord = vec3_add(obj->coord, vec3_scalar_mul(cyl.height, cyl.normal));
	k2 = plane_k(coord, cyl.normal, ray);
	if (k1 <= 0 || k2 <= 0)
		return (0);
	if (vec3_norm(vec3_sub(vec3_add(ray.coord, vec3_scalar_mul(k1, ray.orient)), obj->coord)) > cyl.radius)
		k1 = 0;
	if (vec3_norm(vec3_sub(vec3_add(ray.coord, vec3_scalar_mul(k2, ray.orient)), coord)) > cyl.radius)
		k2 = 0;
	if (k1 <= 0 && k2 <= 0)
		return (0);
	else if (k1 > k2 && k2 > 0)
		return (k2);
	return (k1);
}

int	check_out_of_cylinder(t_object *obj, t_ray ray, double k)
{
	t_cylinder	cyl;
	t_vec3		pos;
	double		len;

	cyl = *(t_cylinder *)obj->info;
	pos = vec3_add(ray.coord, vec3_scalar_mul(k, ray.orient));
	len = vec3_inner_pd(vec3_sub(obj->coord, pos), cyl.normal);
	if (len < 0 || len > cyl.height)
		return (1);
	return (0);
}

double	get_cylinder_k_side(t_object *obj, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	k;
	t_vec3	n;

	n = ((t_cylinder *)obj->info)->normal;
	a = pow(ray.orient.x, 2) * pow(n.x, 2)
		+ pow(ray.orient.y, 2) * pow(n.y, 2)
		+ pow(ray.orient.z, 2) * pow(n.z, 2)
		+ 2 * ray.orient.x * n.x * ray.orient.y * n.y
		+ 2 * ray.orient.y * n.y * ray.orient.z * n.z
		+ 2 * ray.orient.z * n.z * ray.orient.x * n.x;
	b = (n.y * ray.coord.y - n.y * obj->coord.y
			- ray.orient.z * n.z * ray.coord.z + n.z * obj->coord.z
			- n.x * ray.coord.x + n.x * obj->coord.x)
		* (n.x * ray.orient.x - n.y * ray.orient.y - n.z * ray.orient.z);
	c = pow(n.x * ray.coord.x - n.x * obj->coord.x, 2)
		+ pow(n.y * ray.coord.y - n.y * obj->coord.y, 2)
		+ pow(n.z * ray.coord.z - n.z * obj->coord.z, 2)
		- pow(((t_cylinder *)obj->info)->radius, 2);
	if (pow(b, 2) - a * c < 0)
		return (0);
	k = (-b - sqrt(pow(b, 2) - a * c)) / a;
	if (k <= 0 || check_out_of_cylinder(obj, ray, k))
		return (0);
	return (k);
}
