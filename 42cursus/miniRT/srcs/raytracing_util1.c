/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_util1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:38:23 by balee             #+#    #+#             */
/*   Updated: 2023/02/10 05:54:00 by balee            ###   ########.fr       */
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

t_ray	set_ray(t_vec3 pixel, double mat[3][3], t_camera c)
{
	t_ray ray;

	ray.orient.x = pixel.x - (WIDTH / 2);
	ray.orient.y = (HEIGHT / 2) - pixel.y;
	ray.orient.z = pixel.z;
	ray.orient = vec3_mat3_mul(mat, vec3_normal(ray.orient));
	ray.coord.x = c.coord.x;
	ray.coord.y = c.coord.y;
	ray.coord.z = c.coord.z;
	return (ray);
}

t_object	*get_object(t_miniRT miniRT, int n)
{
	t_list	*object;
	int		i;

	i = 1;
	object = miniRT.objects;
	while (i++ < n)
		object = object->next;
	return (object->content);
}
