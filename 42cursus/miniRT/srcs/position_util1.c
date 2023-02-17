/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_util1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:08:13 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 21:40:28 by balee            ###   ########.fr       */
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
	if (k1 > k2)
		k1 = 0;
	else
		k2 = 0;
	if (vec3_norm(vec3_sub(vec3_add(ray.coord,
					vec3_scalar_mul(k1, ray.orient)), obj->coord)) > cyl.radius)
		k1 = 0;
	if (vec3_norm(vec3_sub(vec3_add(ray.coord,
					vec3_scalar_mul(k2, ray.orient)), coord)) > cyl.radius)
		k2 = 0;
	if (k2 > 0)
		return (k2);
	return (k1);
}

int	check_out_of_cylinder(t_object *obj, t_ray ray, double k)
{
	t_cylinder	cyl;
	t_vec3		pos;
	int			len;

	cyl = *(t_cylinder *)obj->info;
	pos = vec3_add(ray.coord, vec3_scalar_mul(k, ray.orient));
	len = vec3_inner_pd(vec3_sub(obj->coord, pos), cyl.normal);
	if (len < 0 || len > cyl.height)
		return (1);
	return (0);
}

static double	det_3x3(t_vec3 a, t_vec3 b, t_vec3 c)
{
	double	det;

	det = a.x * (b.y * c.z - b.z * c.y) \
		- b.x * (a.y * c.z - a.z * c.y) \
		+ c.x * (a.y * b.z - a.z * b.y);
	return (det);
}

double	cyl_side_k_comp(t_cylinder cyl, t_vec3 *o, t_vec3 *d, double *f)
{
	o[3] = ray2point(cyl.height / 2.0, (t_ray){o[2], d[2]});
	if (sqrt(pow(cyl.radius, 2.0) + pow(cyl.height / 2.0, 2.0))
		< vec3_norm(vec3_sub(ray2point(f[3], (t_ray){o[1], d[1]}), o[3]))
			|| f[3] <= 0)
		f[3] = DBL_MAX;
	if (sqrt(pow(cyl.radius, 2.0) + pow(cyl.height / 2.0, 2.0))
		< vec3_norm(vec3_sub(ray2point(f[4], (t_ray){o[1], d[1]}), o[3]))
			|| f[4] <= 0)
		f[4] = DBL_MAX;
	f[3] = double_min(f[3], f[4]);
	if (f[3] == DBL_MAX)
		return (0);
	else
		return (f[3]);
}

double	get_cylinder_k_side(t_object *obj, t_ray ray)
{
	t_cylinder	cyl;
	t_vec3		o[5];
	t_vec3		d[5];
	double		f[10];

	cyl = *(t_cylinder *)obj->info;
	o[1] = ray.coord;
	d[1] = vec3_normal(ray.orient);
	o[2] = obj->coord;
	d[2] = vec3_normal(cyl.normal);
	f[1] = det_3x3(vec3_sub(o[2], o[1]), d[2], vec3_cross_pd(d[1], d[2]))
		/ pow(vec3_norm(vec3_cross_pd(d[1], d[2])), 2.0);
	f[2] = det_3x3(vec3_sub(o[2], o[1]), d[1], vec3_cross_pd(d[1], d[2]))
		/ pow(vec3_norm(vec3_cross_pd(d[1], d[2])), 2.0);
	f[0] = vec3_norm(vec3_sub(ray2point(f[1], ray), \
	ray2point(f[2], (t_ray){o[2], d[2]})));
	f[5] = sqrt(pow(cyl.radius, 2.0) - pow(f[0], 2.0))
		/ sin(vec3_ang_rad(d[1], d[2]));
	f[3] = f[1] + f[5];
	f[4] = f[1] - f[5];
	return (cyl_side_k_comp(cyl, o, d, f));
}
