/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:59 by balee             #+#    #+#             */
/*   Updated: 2023/01/30 18:52:53 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	set_rot_mat(t_camera c, double mat[3][3])
{
	mat[0][2] = c.orient.x;
	mat[1][2] = c.orient.y;
	mat[2][2] = c.orient.z;
	if (c.orient.x == 0 && c.orient.z == 0)
	{
		mat[0][0] = 1;
		mat[1][0] = 0;
		mat[2][0] = 0;
		mat[0][1] = 0;
		mat[1][1] = 1;
		mat[2][1] = -c.orient.y;
	}
	else
	{
		mat[0][0] = c.orient.z / sqrt(pow(c.orient.x, 2) + (c.orient.z, 2));
		mat[1][0] = 0;
		mat[2][0] = -c.orient.x / sqrt(pow(c.orient.x, 2) + (c.orient.z, 2));
		mat[0][1] = c.orient.y * mat[2][0] - c.orient.z * mat[1][0];
		mat[1][1] = c.orient.z * mat[0][0] - c.orient.x * mat[2][0];
		mat[2][1] = c.orient.x * mat[1][0] - c.orient.y * mat[0][0];
	}
}

int	draw(t_miniRT miniRT)
{
	t_vec3	ray;
	double	d;
	double	h;
	double	w;
	double	mat[3][3];

	set_rot_mat(miniRT.camera, mat);
	d = (WIDTH / 2) / tan(miniRT.camera.fov / 2);
	h = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			ray.x = w - (WIDTH / 2);
			ray.y = (HEIGHT / 2) - h;
			ray.z = d;
			vec3_norm(ray, &ray);
			vec3_mat3_mul(mat, ray, &ray);
			w++;
		}
		h++;
	}
}

t_rgb	ray_tracing(t_miniRT miniRT, t_ray ray, int object, int depth)
{
	t_rgb	result;

	if (/*충돌 없음*/)
	{}
	else if ()
	else if (depth < MAX_DEPTH)
	{}
}
