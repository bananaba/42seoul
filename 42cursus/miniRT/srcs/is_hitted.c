/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hitted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:30:26 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 15:59:44 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

double	sphere_hitted(t_object *object, t_ray ray)
{
	double	d;
	double	k;

	d = vec3_norm(vec3_cross_pd(vec3_sub(object->coord, ray.coord),
				ray.orient));
	if (d < 0)
		d *= -1;
	if (((t_sphere *)object->info)->radius < d)
		return (0);
	k = get_k(object, ray);
	if (k <= 0)
		return (0);
	return (k);
}

double	plane_hitted(t_object *object, t_ray ray)
{
	double	k;

	if (vec3_inner_pd(ray.orient, ((t_plane *)object->info)->normal) == 0)
		return (0);
	k = get_k(object, ray);
	if (k <= 0)
		return (0);
	return (k);
}

double	cylinder_hitted(t_object *object, t_ray ray)
{
	double		k;
	double		d;
	t_vec3		coc;
	t_cylinder	cyl;

	cyl = *(t_cylinder *)object->info;
	coc = ray2point(cyl.height / 2.0,
			(t_ray){object->coord, cyl.normal});
	d = vec3_norm(vec3_cross_pd(vec3_sub(coc, ray.coord),
				ray.orient));
	if (1.1 * (sqrt(pow(cyl.height / 2.0, 2.0) + pow(cyl.radius, 2.0))) < d)
		return (0);
	k = get_k(object, ray);
	if (k <= 0)
		return (0);
	return (k);
}

double	check_hitted(t_object *object, t_ray ray)
{
	if (object->type == 'S')
		return (sphere_hitted(object, ray));
	else if (object->type == 'P')
		return (plane_hitted(object, ray));
	else if (object->type == 'C')
		return (cylinder_hitted(object, ray));
	return (0);
}

int	is_hitted(t_miniRT minirt, t_ray ray, int n)
{
	t_list	*object;
	int		i;
	int		hit;
	double	k;
	double	temp;

	object = minirt.objects;
	i = 1;
	hit = 0;
	while (object != NULL)
	{
		if (i != n)
		{
			temp = check_hitted(object->content, ray);
			if (temp != 0 && (hit == 0 || k > temp))
			{
				hit = i;
				k = temp;
			}
		}
		i++;
		object = object->next;
	}
	return (hit);
}
