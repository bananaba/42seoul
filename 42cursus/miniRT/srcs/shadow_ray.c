/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:33:06 by balee             #+#    #+#             */
/*   Updated: 2023/02/12 13:33:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_ray	get_ray(t_light *light, t_vec3 pos)
{
	t_ray	ray;

	ray.coord = pos;
	ray.orient.x = light->coord.x - pos.x;
	ray.orient.y = light->coord.y - pos.y;
	ray.orient.z = light->coord.z - pos.z;
	ray.orient = vec3_normal(ray.orient);
	return (ray);
}

t_rgb	get_specular(t_light *light, t_object *object, t_vec3 pos, t_ray ray)
{
	t_rgb	result;
	t_vec3	r;
	t_vec3	n;

	n = get_normal(object, pos, ray);
	r.x = light->coord.x - pos.x;
	r.y = light->coord.y - pos.y;
	r.z = light->coord.z - pos.z;
	r = vec3_normal(r);
	r = vec3_sub(vec3_scalar_mul(2 * vec3_inner_pd(n, r), n), r);
	result = rgb_scalar_mul(light->rgb, pow(-vec3_inner_pd(r, ray.orient), object->shininess));
	result = rgb_component_mul(result, object->specular);
	return (result);
}

t_rgb	shadow_ray(t_miniRT miniRT, t_ray ray, t_object *object, int n)
{
	t_rgb	result;
	t_vec3	pos;
	t_list	*lights;
	t_light	*light;

	pos = get_pos(object, ray);
	lights = miniRT.lights;
	while (lights != NULL)
	{
		if (is_hitted(miniRT, get_ray(lights->content, pos), n) == 0)
		{
			light = (t_light *)lights->content;
			result = rgb_component_mul(light->rgb, object->diffuse);
			result = rgb_component_add(result, get_specular(light, object, pos, ray));
		}
		lights = lights->next;
	}
	return (result);
}
