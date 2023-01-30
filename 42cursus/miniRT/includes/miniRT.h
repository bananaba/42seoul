/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:36 by balee             #+#    #+#             */
/*   Updated: 2023/01/30 01:46:19 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include "../Libft/libft.h"

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef WIDTH
#  define WIDTH 1920
# endif

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

typedef struct s_ambientLight
{
	double	ratio;
	t_rgb	rgb;
}	t_ambientLight;

typedef struct s_camera
{
	t_vec3	coord;
	t_vec3	orient;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	coord;
	double	ratio;
	t_rgb	rgb;
}	t_light;

typedef struct s_object
{
	t_rgb	ambient;
	t_rgb	diffuse;
	t_rgb	sepcular;
	double	shininess;
	double	opacity;
}	t_object;

typedef struct s_miniRT
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_ambientLight	ambientLight;
	t_list			*lights;
	t_list			*objects;
	t_camera		camera;
}	t_miniRT;

#endif
