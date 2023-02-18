/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:54:32 by balee             #+#    #+#             */
/*   Updated: 2023/02/18 22:50:01 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	get_sphere(t_miniRT *minirt, int fd)
{
	t_object	*obj;

	obj = malloc_obj(minirt, 0, fd);
	obj->type = 'S';
	obj->coord.x = get_num(minirt, fd);
	obj->coord.y = get_num(minirt, fd);
	obj->coord.z = get_num(minirt, fd);
	((t_sphere *)obj->info)->radius = get_num(minirt, fd) / 2;
	if (((t_sphere *)obj->info)->radius < 0)
		wrong_input(minirt, fd, "Minus diameter of sphere!");
	set_color_info(obj, minirt, fd);
}

void	get_plane(t_miniRT *minirt, int fd)
{
	t_object	*obj;

	obj = malloc_obj(minirt, 1, fd);
	obj->type = 'P';
	obj->coord.x = get_num(minirt, fd);
	obj->coord.y = get_num(minirt, fd);
	obj->coord.z = get_num(minirt, fd);
	((t_plane *)obj->info)->normal.x = get_num(minirt, fd);
	((t_plane *)obj->info)->normal.y = get_num(minirt, fd);
	((t_plane *)obj->info)->normal.z = get_num(minirt, fd);
	check_orient(((t_plane *)obj->info)->normal, minirt, fd);
	((t_plane *)obj->info)->normal
		= vec3_normal(((t_plane *)obj->info)->normal);
	set_color_info(obj, minirt, fd);
}

void	get_cylinder(t_miniRT *minirt, int fd)
{
	t_object	*obj;

	obj = malloc_obj(minirt, 2, fd);
	obj->type = 'C';
	obj->coord.x = get_num(minirt, fd);
	obj->coord.y = get_num(minirt, fd);
	obj->coord.z = get_num(minirt, fd);
	((t_cylinder *)obj->info)->normal.x = get_num(minirt, fd);
	((t_cylinder *)obj->info)->normal.y = get_num(minirt, fd);
	((t_cylinder *)obj->info)->normal.z = get_num(minirt, fd);
	check_orient(((t_cylinder *)obj->info)->normal, minirt, fd);
	((t_cylinder *)obj->info)->normal
		= vec3_normal(((t_cylinder *)obj->info)->normal);
	((t_cylinder *)obj->info)->radius = get_num(minirt, fd) / 2;
	if (((t_cylinder *)obj->info)->radius < 0)
		wrong_input(minirt, fd, "Minus diameter of cylinder!");
	((t_cylinder *)obj->info)->height = get_num(minirt, fd);
	if (((t_cylinder *)obj->info)->height < 0)
		wrong_input(minirt, fd, "Minus height of cylinder!");
	set_color_info(obj, minirt, fd);
}
