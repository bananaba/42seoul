/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:36 by balee             #+#    #+#             */
/*   Updated: 2023/02/12 18:46:47 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include "vector.h"
# include "../Libft/libft.h"
# include "../mlx/mlx.h"

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef MAX_DEPTH
#  define MAX_DEPTH 10
# endif

# define KEY_PRESS		2
# define KEY_ESC		53
# define DESTROY_NOTIFY	17

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

typedef struct s_camera
{
	t_vec3	coord;
	t_vec3	orient;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	coord;
	t_rgb	rgb;
}	t_light;

typedef struct s_ray
{
	t_vec3	coord;
	t_vec3	orient;
}	t_ray;

typedef struct s_object
{
	char	type;
	t_rgb	ambient;
	t_rgb	diffuse;
	t_rgb	specular;
	double	shininess;
	t_vec3	coord;
	void	*info;
}	t_object;

typedef struct s_sphere
{
	double	radius;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	normal;
}	t_plane;

typedef struct s_mlx_hpr_image
{
	void	*img;
	char	*canvas;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_miniRT
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_rgb			alight;
	t_list			*lights;
	t_list			*objects;
	t_camera		camera;
}	t_miniRT;

//raytracing
void		draw(t_miniRT miniRT);
t_rgb		ray_tracing(t_miniRT miniRT, t_ray ray, int object, int depth);

//raytracing_util1
void		set_rot_mat(t_camera c, double mat[3][3]);
t_ray		set_ray(t_vec3 pixel, double mat[3][3], t_camera c);
t_object	*get_object(t_miniRT miniRT, int n);

//is_hitted
int			is_hitted(t_miniRT miniRT, t_ray ray, int n);

//rgb_util1
t_rgb		rgb_component_add(t_rgb rgb1, t_rgb rgb2);
t_rgb		rgb_component_mul(t_rgb rgb, t_rgb ratio);
t_rgb		rgb_scalar_mul(t_rgb rgb, double ratio);

//position
t_vec3		get_pos(t_object *object, t_ray ray);
double		get_k(t_object *object, t_ray ray);

//normal
t_vec3		get_normal(t_object *object, t_vec3 pos, t_ray ray);

//shadow_ray
t_rgb		shadow_ray(t_miniRT miniRT, t_ray ray, t_object *object, int n);

#endif
