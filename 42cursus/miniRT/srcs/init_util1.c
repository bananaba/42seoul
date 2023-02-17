/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:15:37 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 17:08:33 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

char	skip_whitespace(int fd, double *temp)
{
	char	c;

	read(fd, &c, 1);
	*temp = 1;
	while (c == ' ' || (c >= 0x9 && c <= 0xd))
		read(fd, &c, 1);
	if (c == '-')
	{
		*temp = -1;
		read(fd, &c, 1);
	}
	return (c);
}

double	get_num(t_miniRT *minirt, int fd)
{
	double	n;
	double	temp;
	char	c;

	c = skip_whitespace(fd, &temp);
	n = 0;
	if (c < '0' || c > '9')
		wrong_input(minirt, fd, "Wrong char in map file!");
	while ((c >= '0' && c <= '9') || c == '.')
	{
		if (temp != 1 && temp != -1)
			temp /= 10;
		if (c != '.')
			n = n * 10 + c - '0';
		else if (temp != 1 && temp != -1)
			wrong_input(minirt, fd, "Double dot in map file!");
		else
			temp /= 10;
		read(fd, &c, 1);
	}
	if (temp != 1 && temp != -1)
		temp *= 10;
	return (n * temp);
}

void	get_ambient_light(t_miniRT *minirt, int fd)
{
	double	ratio;

	if (minirt->checker & 0x1)
		wrong_input(minirt, fd, "More than one ambient light!");
	ratio = get_num(minirt, fd);
	minirt->alight.r = get_num(minirt, fd);
	minirt->alight.g = get_num(minirt, fd);
	minirt->alight.b = get_num(minirt, fd);
	check_rgb(minirt->alight, minirt, fd);
	minirt->alight = rgb_scalar_mul(minirt->alight, ratio);
	minirt->checker |= 0x1;
}

void	get_camera(t_miniRT *minirt, int fd)
{
	if (minirt->checker & (0x1 << 1))
		wrong_input(minirt, fd, "More than one camera!");
	minirt->camera.coord.x = get_num(minirt, fd);
	minirt->camera.coord.y = get_num(minirt, fd);
	minirt->camera.coord.z = get_num(minirt, fd);
	minirt->camera.orient.x = get_num(minirt, fd);
	minirt->camera.orient.y = get_num(minirt, fd);
	minirt->camera.orient.z = get_num(minirt, fd);
	check_orient(minirt->camera.orient, minirt, fd);
	minirt->camera.orient = vec3_normal(minirt->camera.orient);
	minirt->camera.fov = get_num(minirt, fd);
	if (minirt->camera.fov >= 180 || minirt->camera.fov <= 0)
		wrong_input(minirt, fd, "Out of camera fov range!");
	minirt->checker |= (0x1 << 1);
}

void	get_light(t_miniRT *minirt, int fd)
{
	t_list	*light;
	double	ratio;

	light = (t_list *)malloc(sizeof(t_list));
	if (light == NULL)
		wrong_input(minirt, fd, "Memory allocation fail!");
	if (minirt->lights == NULL)
		minirt->lights = light;
	else
		ft_lstadd_back(&minirt->lights, light);
	light->next = NULL;
	light->content = (t_light *)malloc(sizeof(t_light));
	if (light->content == NULL)
		wrong_input(minirt, fd, "Memory allocation fail!");
	((t_light *)light->content)->coord.x = get_num(minirt, fd);
	((t_light *)light->content)->coord.y = get_num(minirt, fd);
	((t_light *)light->content)->coord.z = get_num(minirt, fd);
	ratio = get_num(minirt, fd);
	((t_light *)light->content)->rgb.r = get_num(minirt, fd);
	((t_light *)light->content)->rgb.g = get_num(minirt, fd);
	((t_light *)light->content)->rgb.b = get_num(minirt, fd);
	check_rgb(((t_light *)light->content)->rgb, minirt, fd);
	((t_light *)light->content)->rgb
		= rgb_scalar_mul(((t_light *)light->content)->rgb, ratio);
}
