/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:11:01 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 17:09:09 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_rgb	set_rgb_color(t_miniRT *minirt, int fd, double temp, char c)
{
	t_rgb	rgb;

	rgb.r = 0;
	while ((c >= '0' && c <= '9') || c == '.')
	{
		if (temp != 1 && temp != -1)
			temp /= 10;
		if (c != '.')
			rgb.r = rgb.r * 10 + c - '0';
		else if (temp != 1 && temp != -1)
			wrong_input(minirt, fd, "Double dot in map file!");
		else
			temp /= 10;
		read(fd, &c, 1);
	}
	if (temp != 1 && temp != -1)
		rgb.r *= 10;
	rgb.r *= temp;
	rgb.g = get_num(minirt, fd);
	rgb.b = get_num(minirt, fd);
	check_rgb(rgb, minirt, fd);
	return (rgb);
}

int	set_object_color2(t_object *obj, char c1, char c2)
{
	if (c1 == 'p' && c2 == 'r')
		set_perl_color(obj);
	else if (c1 == 'r' && c2 == 'b')
		set_ruby_color(obj);
	else if (c1 == 't' && c2 == 'q')
		set_turquoise_color(obj);
	else if (c1 == 'b' && c2 == 'p')
		set_black_plastic_color(obj);
	else if (c1 == 'c' && c2 == 'p')
		set_cyan_plastic_color(obj);
	else if (c1 == 'g' && c2 == 'p')
		set_green_plastic_color(obj);
	else if (c1 == 'r' && c2 == 'p')
		set_red_plastic_color(obj);
	else if (c1 == 'w' && c2 == 'p')
		set_white_plastic_color(obj);
	else if (c1 == 'y' && c2 == 'p')
		set_yellow_plastic_color(obj);
	else
		return (1);
	return (0);
}

void	set_object_color1(t_object *obj, t_miniRT *minirt, int fd, char c1)
{
	char	c2;

	read(fd, &c2, 1);
	if (c1 == 'b' && c2 == 's')
		set_brass_color(obj);
	else if (c1 == 'b' && c2 == 'z')
		set_bronze_color(obj);
	else if (c1 == 'c' && c2 == 'r')
		set_chrome_color(obj);
	else if (c1 == 'c' && c2 == 'o')
		set_copper_color(obj);
	else if (c1 == 'g' && c2 == 'd')
		set_gold_color(obj);
	else if (c1 == 't' && c2 == 'n')
		set_tin_color(obj);
	else if (c1 == 's' && c2 == 'v')
		set_silver_color(obj);
	else if (c1 == 'e' && c2 == 'm')
		set_emerald_color(obj);
	else if (c1 == 'j' && c2 == 'd')
		set_jade_color(obj);
	else if (c1 == 'o' && c2 == 's')
		set_obsidian_color(obj);
	else if (set_object_color2(obj, c1, c2))
		wrong_input(minirt, fd, "Undefined material!");
}

void	set_color_info(t_object *obj, t_miniRT *minirt, int fd)
{
	double	temp;
	char	c;

	c = skip_whitespace(fd, &temp);
	if (c >= '0' && c <= '9')
	{
		obj->diffuse = set_rgb_color(minirt, fd, temp, c);
		obj->ambient = obj->diffuse;
		obj->specular = obj->diffuse;
		obj->shininess = 20;
	}
	else
		set_object_color1(obj, minirt, fd, c);
}
