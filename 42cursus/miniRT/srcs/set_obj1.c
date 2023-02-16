/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:51:02 by balee             #+#    #+#             */
/*   Updated: 2023/02/14 18:59:14 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	set_brass_color(t_object *obj)
{
	obj->ambient.r = 0.329412;
	obj->ambient.g = 0.223529;
	obj->ambient.b = 0.027451;
	obj->diffuse.r = 0.780392;
	obj->diffuse.g = 0.568627;
	obj->diffuse.b = 0.113725;
	obj->specular.r = 0.992157;
	obj->specular.g = 0.941176;
	obj->specular.b = 0.807843;
	obj->shininess = 27.8974;
}

void	set_bronze_color(t_object *obj)
{
	obj->ambient.r = 0.2125;
	obj->ambient.g = 0.1275;
	obj->ambient.b = 0.054;
	obj->diffuse.r = 0.714;
	obj->diffuse.g = 0.4284;
	obj->diffuse.b = 0.18144;
	obj->specular.r = 0.393548;
	obj->specular.g = 0.271906;
	obj->specular.b = 0.166721;
	obj->shininess = 25.6;
}

void	set_chrome_color(t_object *obj)
{
	obj->ambient.r = 0.25;
	obj->ambient.g = 0.25;
	obj->ambient.b = 0.25;
	obj->diffuse.r = 0.4;
	obj->diffuse.g = 0.4;
	obj->diffuse.b = 0.4;
	obj->specular.r = 0.774597;
	obj->specular.g = 0.774597;
	obj->specular.b = 0.774597;
	obj->shininess = 76.8f;
}

void	set_copper_color(t_object *obj)
{
	obj->ambient.r = 0.19125;
	obj->ambient.g = 0.0735;
	obj->ambient.b = 0.0225;
	obj->diffuse.r = 0.7038;
	obj->diffuse.g = 0.27048;
	obj->diffuse.b = 0.0828;
	obj->specular.r = 0.256777;
	obj->specular.g = 0.137622;
	obj->specular.b = 0.086014;
	obj->shininess = 12.8;
}

void	set_gold_color(t_object *obj)
{
	obj->ambient.r = 0.24725;
	obj->ambient.g = 0.1995;
	obj->ambient.b = 0.0745;
	obj->diffuse.r = 0.75164;
	obj->diffuse.g = 0.60648;
	obj->diffuse.b = 0.22648;
	obj->specular.r = 0.628281;
	obj->specular.g = 0.555802;
	obj->specular.b = 0.366065;
	obj->shininess = 51.2;
}
