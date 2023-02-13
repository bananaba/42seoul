/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:54:32 by balee             #+#    #+#             */
/*   Updated: 2023/02/13 22:44:09 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	get_sphere(t_miniRT *minirt, char **str)
{
	t_object	*obj;

	obj = malloc_obj(minirt, 0);
	obj->type = 'S';
	obj->coord.x = get_num(minirt, str);
	obj->coord.y = get_num(minirt, str);
	obj->coord.z = get_num(minirt, str);
	((t_sphere *)obj->info)->radius = get_num(minirt, str) / 2;
	set_color_info(obj, minirt, str);
}

void	get_plane(t_miniRT *minirt, char **str)
{
	t_object	*obj;

	obj = malloc_obj(minirt, 1);
	obj->type = 'P';
	obj->coord.x = get_num(minirt, str);
	obj->coord.y = get_num(minirt, str);
	obj->coord.z = get_num(minirt, str);
	((t_plane *)obj->info)->normal.x = get_num(minirt, str);
	((t_plane *)obj->info)->normal.y = get_num(minirt, str);
	((t_plane *)obj->info)->normal.z = get_num(minirt, str);
	check_orient(((t_plane *)obj->info)->normal, minirt);
	((t_plane *)obj->info)->normal
		= vec3_normal(((t_plane *)obj->info)->normal);
	set_color_info(obj, minirt, str);
}

void	get_cylinder(t_miniRT *minirt, char **str)
{
	t_object	*obj;

	obj = malloc_obj(minirt, 2);
	obj->type = 'C';
	obj->coord.x = get_num(minirt, str);
	obj->coord.y = get_num(minirt, str);
	obj->coord.z = get_num(minirt, str);
	((t_cylinder *)obj->info)->normal.x = get_num(minirt, str);
	((t_cylinder *)obj->info)->normal.y = get_num(minirt, str);
	((t_cylinder *)obj->info)->normal.z = get_num(minirt, str);
	check_orient(((t_cylinder *)obj->info)->normal, minirt);
	((t_cylinder *)obj->info)->normal
		= vec3_normal(((t_cylinder *)obj->info)->normal);
	((t_cylinder *)obj->info)->radius = get_num(minirt, str) / 2;
	((t_cylinder *)obj->info)->height = get_num(minirt, str);
	set_color_info(obj, minirt, str);
}
