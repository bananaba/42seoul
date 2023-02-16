/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:51:13 by balee             #+#    #+#             */
/*   Updated: 2023/02/14 19:05:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	set_tin_color(t_object *obj)
{
	obj->ambient.r = 0.105882;
	obj->ambient.g = 0.058824;
	obj->ambient.b = 0.113725;
	obj->diffuse.r = 0.427451;
	obj->diffuse.g = 0.470588;
	obj->diffuse.b = 0.541176;
	obj->specular.r = 0.333333;
	obj->specular.g = 0.333333;
	obj->specular.b = 0.521569;
	obj->shininess = 9.84615;
}

void	set_silver_color(t_object *obj)
{
	obj->ambient.r = 0.19225;
	obj->ambient.g = 0.19225;
	obj->ambient.b = 0.19225;
	obj->diffuse.r = 0.50754;
	obj->diffuse.g = 0.50754;
	obj->diffuse.b = 0.50754;
	obj->specular.r = 0.508273;
	obj->specular.g = 0.508273;
	obj->specular.b = 0.508273;
	obj->shininess = 51.2;
}

void	set_emerald_color(t_object *obj)
{
	obj->ambient.r = 0.0215;
	obj->ambient.g = 0.1745;
	obj->ambient.b = 0.0215;
	obj->diffuse.r = 0.07568;
	obj->diffuse.g = 0.61424;
	obj->diffuse.b = 0.07568;
	obj->specular.r = 0.633;
	obj->specular.g = 0.727811;
	obj->specular.b = 0.633;
	obj->shininess = 76.8f;
}

void	set_jade_color(t_object *obj)
{
	obj->ambient.r = 0.135;
	obj->ambient.g = 0.2225;
	obj->ambient.b = 0.1575;
	obj->diffuse.r = 0.5;
	obj->diffuse.g = 0.89;
	obj->diffuse.b = 0.63;
	obj->specular.r = 0.316228;
	obj->specular.g = 0.316228;
	obj->specular.b = 0.316228;
	obj->shininess = 12.8;
}

void	set_obsidian_color(t_object *obj)
{
	obj->ambient.r = 0.05375;
	obj->ambient.g = 0.05;
	obj->ambient.b = 0.06625;
	obj->diffuse.r = 0.18275;
	obj->diffuse.g = 0.17;
	obj->diffuse.b = 0.22525;
	obj->specular.r = 0.332741;
	obj->specular.g = 0.328634;
	obj->specular.b = 0.346435;
	obj->shininess = 38.4;
}
