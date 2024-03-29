/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_util1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:38:23 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 16:08:17 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	set_rot_mat(t_camera c, double mat[3][3])
{
	mat[2][0] = c.orient.x;
	mat[2][1] = c.orient.y;
	mat[2][2] = c.orient.z;
	if (c.orient.x == 0 && c.orient.z == 0)
	{
		mat[0][0] = 1;
		mat[0][1] = 0;
		mat[0][2] = 0;
		mat[1][0] = 0;
		mat[1][1] = 1;
		mat[1][2] = -c.orient.y;
	}
	else
	{
		mat[0][0] = c.orient.z / sqrt(pow(c.orient.x, 2) + pow(c.orient.z, 2));
		mat[0][1] = 0;
		mat[0][2] = -c.orient.x / sqrt(pow(c.orient.x, 2) + pow(c.orient.z, 2));
		mat[1][0] = c.orient.y * mat[0][2] - c.orient.z * mat[0][1];
		mat[1][1] = c.orient.z * mat[0][0] - c.orient.x * mat[0][2];
		mat[1][2] = c.orient.x * mat[0][1] - c.orient.y * mat[0][0];
	}
}

t_ray	set_ray(t_vec3 pixel, double mat[3][3], t_camera c)
{
	t_ray	ray;

	ray.orient.x = (WIDTH / 2) - pixel.x;
	ray.orient.y = (HEIGHT / 2) - pixel.y;
	ray.orient.z = pixel.z;
	ray.orient = vec3_mat3_mul(mat, vec3_normal(ray.orient));
	ray.coord.x = c.coord.x;
	ray.coord.y = c.coord.y;
	ray.coord.z = c.coord.z;
	return (ray);
}

t_object	*get_object(t_miniRT minirt, int n)
{
	t_list	*object;
	int		i;

	i = 1;
	object = minirt.objects;
	while (i++ < n)
		object = object->next;
	return (object->content);
}

t_rgb	render_pixel(t_vec3 pixel, double mat[3][3], t_miniRT minirt)
{
	t_ray	ray;
	t_rgb	color;
	int		i;

	color = (t_rgb){0, 0, 0};
	i = -1;
	while (++i < 9)
	{
		ray.orient.x = (WIDTH / 2) - pixel.x + (0.33 - 0.33 * (i / 3));
		ray.orient.y = (HEIGHT / 2) - pixel.y + (0.33 - 0.33 * (i % 3));
		ray.orient.z = pixel.z;
		ray.orient = vec3_mat3_mul(mat, vec3_normal(ray.orient));
		ray.coord.x = minirt.camera.coord.x;
		ray.coord.y = minirt.camera.coord.y;
		ray.coord.z = minirt.camera.coord.z;
		color = rgb_component_add(color,
				rgb_scalar_mul(ray_tracing(minirt, ray, 0, 0), 1.0 / 9.0));
	}
	return (color);
}
