/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:36 by balee             #+#    #+#             */
/*   Updated: 2023/02/13 22:43:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "./vector.h"
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

typedef struct s_cylinder
{
	t_vec3	normal;
	double	radius;
	double	height;
}	t_cylinder;

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
	char			*str;
	t_img			img;
	t_rgb			alight;
	t_list			*lights;
	t_list			*objects;
	t_camera		camera;
	int				checker;
}	t_miniRT;

//init
void		init_minirt(t_miniRT *minirt, char *file);

//init_util1
void		get_ambient_light(t_miniRT *minirt, char **str);
void		get_camera(t_miniRT *minirt, char **str);
void		get_light(t_miniRT *minirt, char **str);
double		get_num(t_miniRT *minirt, char **str);
void		skip_whitespace(char **str, double *temp);

//init_util2
void		wrong_input(t_miniRT *minirt);
void		check_rgb(t_rgb color, t_miniRT *minirt);
void		check_orient(t_vec3 orient, t_miniRT *minirt);

//init_util3
void		get_objects(t_miniRT *minirt, char **str);
t_object	*malloc_obj(t_miniRT *minirt, int type);
void		malloc_info(t_miniRT *minirt, int type, t_object *obj);

//init_util4
void		get_sphere(t_miniRT *minirt, char **str);
void		get_plane(t_miniRT *minirt, char **str);
void		get_cylinder(t_miniRT *minirt, char **str);

//init_util5
void		set_color_info(t_object *obj, t_miniRT *minirt, char **str);

//raytracing
void		draw(t_miniRT minirt);
t_rgb		ray_tracing(t_miniRT minirt, t_ray ray, int object, int depth);

//raytracing_util1
void		set_rot_mat(t_camera c, double mat[3][3]);
t_ray		set_ray(t_vec3 pixel, double mat[3][3], t_camera c);
t_object	*get_object(t_miniRT minirt, int n);

//is_hitted
int			is_hitted(t_miniRT minirt, t_ray ray, int n);

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
t_rgb		shadow_ray(t_miniRT minirt, t_ray ray, t_object *object, int n);

//exit
void		free_all(t_miniRT *minirt);
int			exit_err(void);
int			destroy_notify(t_miniRT *minirt);

#endif
