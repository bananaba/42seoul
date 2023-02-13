/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:11:01 by balee             #+#    #+#             */
/*   Updated: 2023/02/13 22:42:43 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_rgb	set_rgb_color(t_miniRT *minirt, char **str, double temp)
{
	t_rgb	rgb;

	while ((**str >= '0' && **str <= '9') || **str == '.')
	{
		if (temp != 1 && temp != -1)
			temp /= 10;
		if (**str != '.')
			rgb.r = rgb.r * 10 + **str - '0';
		else if (temp != 1 && temp != -1)
			wrong_input(minirt);
		else
			temp /= 10;
		(*str)++;
	}
	if (temp != 1 && temp != -1)
		rgb.r *= 10;
	rgb.r *= temp;
	rgb.g = get_num(minirt, str);
	rgb.b = get_num(minirt, str);
	check_rgb(rgb, minirt);
	return (rgb);
}

// void	set_object_color(t_object *obj, t_miniRT *minirt, char **str, char c1)
// {
// 	char	c2;

// 	read(fd, &c2, 1);
// 	if (c1 == 'b' && c2 == 's')
// 		set_brass_color(obj);
// 	else if (c1 == 'b' && c2 == 'z')
// 		set_bronze_color(obj);
// 	else if (c1 == 'c' && c2 == 'r')
// 		set_chrome_color(obj);
// 	else if (c1 == 'c' && c2 == 'o')
// 		set_copper_color(obj);
// 	else if (c1 == 'g' && c2 == 'd')
// 		set_gold_color(obj);
// 	else if (c1 == 't' && c2 == 'n')
// 		set_tin_color(obj);
// 	else if (c1 == 's' && c2 == 'v')
// 		set_silver_color(obj);
// 	else if (c1 == 'e' && c2 == 'm')
// 		set_emerald_color(obj);
// 	else if (c1 == 'j' && c2 == 'd')
// 		set_jade_color(obj);
// 	else
// 		;
// }

void	set_color_info(t_object *obj, t_miniRT *minirt, char **str)
{
	double	temp;

	skip_whitespace(str, &temp);
	if (**str >= '0' && **str <= '9')
	{
		obj->diffuse = set_rgb_color(minirt, str, temp);
		obj->ambient = obj->diffuse;
		obj->specular = obj->diffuse;
		obj->shininess = 20;
	}
	// else
	// 	set_object_color(obj, minirt, fd, c);
}
