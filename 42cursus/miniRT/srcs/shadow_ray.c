/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:33:06 by balee             #+#    #+#             */
/*   Updated: 2023/02/18 23:48:10 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_ray	get_ray(t_light *light, t_vec3 pos)
{
	t_ray	ray;

	ray.coord = pos;
	ray.orient = vec3_sub(light->coord, pos);
	ray.orient = vec3_normal(ray.orient);
	return (ray);
}

t_rgb	get_specular(t_light *light, t_object *object, t_vec3 pos, t_ray ray)
{
	t_rgb	result;
	t_vec3	r;
	t_vec3	n;
	double	max;

	n = get_normal(object, pos, ray);
	r = vec3_sub(light->coord, pos);
	r = vec3_normal(r);
	r = vec3_sub(vec3_scalar_mul(2 * vec3_inner_pd(n, r), n), r);
	max = -vec3_inner_pd(r, ray.orient);
	if (max < 0)
		max = 0;
	result = rgb_scalar_mul(light->rgb, pow(max, object->shininess));
	result = rgb_component_mul(result, object->specular);
	return (result);
}

t_rgb	get_diffuse(t_light *light, t_object *object, t_vec3 pos, t_ray ray)
{
	t_rgb	result;
	t_vec3	r;
	t_vec3	n;
	double	max;

	n = get_normal(object, pos, ray);
	r = vec3_sub(light->coord, pos);
	r = vec3_normal(r);
	max = vec3_inner_pd(n, r);
	if (max < 0)
		max = 0;
	result = rgb_scalar_mul(light->rgb, max);
	result = rgb_component_mul(result, object->diffuse);
	return (result);
}

int	light_hitted(t_miniRT minirt, t_ray ray, int n, double k)
{
	t_list	*object;
	int		i;
	int		hit;
	double	temp;

	object = minirt.objects;
	i = 1;
	hit = 0;
	while (object != NULL)
	{
		if (i != n)
		{
			temp = check_hitted(object->content, ray);
			if (temp != 0 && k - temp > -0.000000000001
				&& temp > 0.000000000001)
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

t_rgb	shadow_ray(t_miniRT minirt, t_ray ray, t_object *object, int n)
{
	t_rgb	result;
	t_vec3	pos;
	t_list	*lights;
	t_light	*light;
	double	k;

	pos = get_pos(object, ray);
	lights = minirt.lights;
	result.r = 0;
	result.g = 0;
	result.b = 0;
	while (lights != NULL)
	{
		light = (t_light *)lights->content;
		k = vec3_norm(vec3_sub(light->coord, pos));
		if (light_hitted(minirt, get_ray(light, pos), n, k) == 0)
		{
			result = rgb_component_add(result,
					get_diffuse(light, object, pos, ray));
			result = rgb_component_add(result,
					get_specular(light, object, pos, ray));
		}
		lights = lights->next;
	}
	return (result);
}
