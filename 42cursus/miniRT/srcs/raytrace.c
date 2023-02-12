/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:59 by balee             #+#    #+#             */
/*   Updated: 2023/02/12 21:11:55 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	draw_pixel(t_miniRT miniRT, t_rgb rgb, int x, int y)
{
	unsigned int	color;
	char			*pos;
	t_img			*img;

	img = &miniRT.img;
	// if (rgb.r > 255)
	// 	color = 255 * 0x010000;
	// else
		color = (unsigned int)rgb.r * 0x010000;
	// if (rgb.g > 255)
	// 	color += 255 * 0x000100;
	// else
		color += (unsigned int)rgb.g * 0x000100;
	// if (rgb.b > 255)
	// 	color += 255;
	// else
		color += (unsigned int)rgb.b;
	pos = img->canvas + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pos = color;
}

void	draw(t_miniRT miniRT)
{
	t_vec3	pixel;
	t_ray	ray;
	t_rgb	color;
	double	mat[3][3];

	set_rot_mat(miniRT.camera, mat);
	pixel.z = (WIDTH / 2.0) / tan(miniRT.camera.fov / 360.0 * M_PI);
	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			ray = set_ray(pixel, mat, miniRT.camera);
			color = ray_tracing(miniRT, ray, 0, 0);
			draw_pixel(miniRT, color, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

t_ray	reflection_ray(t_object *object, t_ray ray)
{
	t_vec3	pos;
	t_vec3	n;
	t_ray	result;

	pos = get_pos(object, ray);
	n = get_normal(object, pos, ray);
	result.coord = pos;
	result.orient = vec3_sub(ray.orient, vec3_scalar_mul(2 * vec3_inner_pd(n, ray.orient), n));
	return (result);
}

t_rgb	ray_tracing(t_miniRT miniRT, t_ray ray, int n, int depth)
{
	t_rgb		result;
	t_object	*object;

	n = is_hitted(miniRT, ray, n);
	if (!n)
		return (miniRT.alight);
	else
	{
		object = get_object(miniRT, n);
		result = rgb_component_mul(miniRT.alight, object->ambient);
		result = rgb_component_add(result, shadow_ray(miniRT, ray, object, n));
		if (depth < MAX_DEPTH)
			result = rgb_component_add(result,rgb_component_mul(ray_tracing(miniRT, reflection_ray(object, ray), n, depth + 1), rgb_scalar_mul(object->specular, 0.2)));
		if (result.r > 255)
			result.r = 255;
		if (result.g > 255)
			result.g = 255;
		if (result.b > 255)
			result.b = 255;
	}
	return (result);
}
