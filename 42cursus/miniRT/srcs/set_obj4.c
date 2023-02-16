/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:51:26 by balee             #+#    #+#             */
/*   Updated: 2023/02/14 19:22:30 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	set_green_plastic_color(t_object *obj)
{
	obj->ambient.r = 0.0;
	obj->ambient.g = 0.0;
	obj->ambient.b = 0.0;
	obj->diffuse.r = 0.1;
	obj->diffuse.g = 0.35;
	obj->diffuse.b = 0.1;
	obj->specular.r = 0.45;
	obj->specular.g = 0.55;
	obj->specular.b = 0.45;
	obj->shininess = 32.0;
}

void	set_red_plastic_color(t_object *obj)
{
	obj->ambient.r = 0.0;
	obj->ambient.g = 0.0;
	obj->ambient.b = 0.0;
	obj->diffuse.r = 0.5;
	obj->diffuse.g = 0.0;
	obj->diffuse.b = 0.0;
	obj->specular.r = 0.7;
	obj->specular.g = 0.6;
	obj->specular.b = 0.6;
	obj->shininess = 32.0;
}

void	set_white_plastic_color(t_object *obj)
{
	obj->ambient.r = 0.0;
	obj->ambient.g = 0.0;
	obj->ambient.b = 0.0;
	obj->diffuse.r = 0.55;
	obj->diffuse.g = 0.55;
	obj->diffuse.b = 0.55;
	obj->specular.r = 0.70;
	obj->specular.g = 0.70;
	obj->specular.b = 0.70;
	obj->shininess = 32.0;
}

void	set_yellow_plastic_color(t_object *obj)
{
	obj->ambient.r = 0.0;
	obj->ambient.g = 0.0;
	obj->ambient.b = 0.0;
	obj->diffuse.r = 0.5;
	obj->diffuse.g = 0.5;
	obj->diffuse.b = 0.0;
	obj->specular.r = 0.60;
	obj->specular.g = 0.60;
	obj->specular.b = 0.50;
	obj->shininess = 32.0;
}
