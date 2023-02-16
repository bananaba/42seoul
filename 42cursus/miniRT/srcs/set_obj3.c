/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:51:19 by balee             #+#    #+#             */
/*   Updated: 2023/02/15 03:47:42 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/miniRT.h"

void	set_perl_color(t_object *obj)
{
	obj->ambient.r = 0.25;
	obj->ambient.g = 0.20725;
	obj->ambient.b = 0.20725;
	obj->diffuse.r = 1.0;
	obj->diffuse.g = 0.829;
	obj->diffuse.b = 0.829;
	obj->specular.r = 0.296648;
	obj->specular.g = 0.296648;
	obj->specular.b = 0.296648;
	obj->shininess = 11.264;
}

void	set_ruby_color(t_object *obj)
{
	obj->ambient.r = 0.1745;
	obj->ambient.g = 0.01175;
	obj->ambient.b = 0.01175;
	obj->diffuse.r = 0.61424;
	obj->diffuse.g = 0.04136;
	obj->diffuse.b = 0.04136;
	obj->specular.r = 0.727811;
	obj->specular.g = 0.626959;
	obj->specular.b = 0.626959;
	obj->shininess = 76.8;
}

void	set_turquoise_color(t_object *obj)
{
	obj->ambient.r = 0.1;
	obj->ambient.g = 0.18725;
	obj->ambient.b = 0.1745;
	obj->diffuse.r = 0.396;
	obj->diffuse.g = 0.74151;
	obj->diffuse.b = 0.69102;
	obj->specular.r = 0.297254;
	obj->specular.g = 0.30829;
	obj->specular.b = 0.306678;
	obj->shininess = 12.8;
}

void	set_black_plastic_color(t_object *obj)
{
	obj->ambient.r = 0.0;
	obj->ambient.g = 0.0;
	obj->ambient.b = 0.0;
	obj->diffuse.r = 0.01;
	obj->diffuse.g = 0.01;
	obj->diffuse.b = 0.01;
	obj->specular.r = 0.50;
	obj->specular.g = 0.50;
	obj->specular.b = 0.50;
	obj->shininess = 32.0;
}

void	set_cyan_plastic_color(t_object *obj)
{
	obj->ambient.r = 0.0;
	obj->ambient.g = 0.1;
	obj->ambient.b = 0.06;
	obj->diffuse.r = 0.0;
	obj->diffuse.g = 0.50980392;
	obj->diffuse.b = 0.50980392;
	obj->specular.r = 0.50196078;
	obj->specular.g = 0.50196078;
	obj->specular.b = 0.50196078;
	obj->shininess = 32.0;
}
