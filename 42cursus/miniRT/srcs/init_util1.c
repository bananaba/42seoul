/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:15:37 by balee             #+#    #+#             */
/*   Updated: 2023/02/13 22:56:49 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	skip_whitespace(char **str, double *temp)
{
	(*str)++;
	*temp = 1;
	while (**str == ' ' || (**str >= 0x9 && **str <= 0xd))
		(*str)++;
	if (**str == '-')
	{
		*temp = -1;
		(*str)++;
	}
}

double	get_num(t_miniRT *minirt, char **str)
{
	double	n;
	double	temp;

	skip_whitespace(str, &temp);
	if (**str < '0' || **str > '9')
		wrong_input(minirt);
	while ((**str >= '0' && **str <= '9') || **str == '.')
	{
		if (temp != 1 && temp != -1)
			temp /= 10;
		if (**str != '.')
			n = n * 10 + **str - '0';
		else if (temp != 1 && temp != -1)
			wrong_input(minirt);
		else
			temp /= 10;
		(*str)++;
	}
	if (temp != 1 && temp != -1)
		temp *= 10;
	return (n * temp);
}

void	get_ambient_light(t_miniRT *minirt, char **str)
{
	double	ratio;

	if (minirt->checker & 0x1)
		wrong_input(minirt);
	ratio = get_num(minirt, str);
	printf("%p\n", *str);
	minirt->alight.r = get_num(minirt, str);
	printf("%p\n", *str);
	minirt->alight.g = get_num(minirt, str);
	printf("%p\n", *str);
	minirt->alight.b = get_num(minirt, str);
	printf("%p\n", *str);
	check_rgb(minirt->alight, minirt);
	minirt->alight = rgb_scalar_mul(minirt->alight, ratio);
	minirt->checker |= 1;
}

void	get_camera(t_miniRT *minirt, char **str)
{
	if (minirt->checker & (0x1 << 1))
		wrong_input(minirt);
	minirt->camera.coord.x = get_num(minirt, str);
	minirt->camera.coord.y = get_num(minirt, str);
	minirt->camera.coord.z = get_num(minirt, str);
	minirt->camera.orient.x = get_num(minirt, str);
	minirt->camera.orient.y = get_num(minirt, str);
	minirt->camera.orient.z = get_num(minirt, str);
	check_orient(minirt->camera.orient, minirt);
	minirt->camera.orient = vec3_normal(minirt->camera.orient);
	minirt->camera.fov = get_num(minirt, str);
}

void	get_light(t_miniRT *minirt, char **str)
{
	t_list	*light;
	double	ratio;

	light = minirt->lights;
	while (light != NULL)
		light = light->next;
	light = (t_list *)malloc(sizeof(t_list));
	if (light == NULL)
		wrong_input(minirt);
	light->next = NULL;
	light->content = (t_light *)malloc(sizeof(t_light));
	if (light->content == NULL)
		wrong_input(minirt);
	((t_light *)light->content)->coord.x = get_num(minirt, str);
	((t_light *)light->content)->coord.y = get_num(minirt, str);
	((t_light *)light->content)->coord.z = get_num(minirt, str);
	ratio = get_num(minirt, str);
	((t_light *)light->content)->rgb.r = get_num(minirt, str);
	((t_light *)light->content)->rgb.g = get_num(minirt, str);
	((t_light *)light->content)->rgb.b = get_num(minirt, str);
	check_rgb(((t_light *)light->content)->rgb, minirt);
	((t_light *)light->content)->rgb
		= rgb_scalar_mul(((t_light *)light->content)->rgb, ratio);
}
