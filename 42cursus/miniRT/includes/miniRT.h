/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:05:36 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 17:02:34 by balee            ###   ########.fr       */
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
# include <float.h>
# include "./vector.h"
# include "../Libft/libft.h"
# include "../mlx/mlx.h"

# ifndef HEIGHT
#  define HEIGHT 720
# endif

# ifndef WIDTH
#  define WIDTH 1280
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
void		get_ambient_light(t_miniRT *minirt, int fd);
void		get_camera(t_miniRT *minirt, int fd);
void		get_light(t_miniRT *minirt, int fd);
double		get_num(t_miniRT *minirt, int fd);
char		skip_whitespace(int fd, double *temp);

//init_util2
void		wrong_input(t_miniRT *minirt, int fd, char *str);
void		check_rgb(t_rgb color, t_miniRT *minirt, int fd);
void		check_orient(t_vec3 orient, t_miniRT *minirt, int fd);

//init_util3
void		get_objects(t_miniRT *minirt, int fd, char c1);
t_object	*malloc_obj(t_miniRT *minirt, int type, int fd);
void		malloc_info(t_miniRT *minirt, int type, t_object *obj, int fd);

//init_util4
void		get_sphere(t_miniRT *minirt, int fd);
void		get_plane(t_miniRT *minirt, int fd);
void		get_cylinder(t_miniRT *minirt, int fd);

//init_util5
void		set_color_info(t_object *obj, t_miniRT *minirt, int fd);

//raytracing
void		draw(t_miniRT minirt);
t_rgb		ray_tracing(t_miniRT minirt, t_ray ray, int object, int depth);

//raytracing_util1
void		set_rot_mat(t_camera c, double mat[3][3]);
t_ray		set_ray(t_vec3 pixel, double mat[3][3], t_camera c);
t_object	*get_object(t_miniRT minirt, int n);

//is_hitted
int			is_hitted(t_miniRT minirt, t_ray ray, int n);
double		check_hitted(t_object *object, t_ray ray);

//rgb_util1
t_rgb		rgb_component_add(t_rgb rgb1, t_rgb rgb2);
t_rgb		rgb_component_mul(t_rgb rgb, t_rgb ratio);
t_rgb		rgb_scalar_mul(t_rgb rgb, double ratio);

//position
t_vec3		get_pos(t_object *object, t_ray ray);
double		get_k(t_object *object, t_ray ray);
double		plane_k(t_vec3 coord, t_vec3 normal, t_ray ray);

//position_util1
double		get_cylinder_k_base(t_object *obj, t_ray ray);
double		get_cylinder_k_side(t_object *obj, t_ray ray);

//normal
t_vec3		get_normal(t_object *object, t_vec3 pos, t_ray ray);

//shadow_ray
t_rgb		shadow_ray(t_miniRT minirt, t_ray ray, t_object *object, int n);

//exit
void		free_all(t_miniRT *minirt);
int			exit_err(char *str);
int			destroy_notify(t_miniRT *minirt);

void		set_brass_color(t_object *obj);
void		set_bronze_color(t_object *obj);
void		set_chrome_color(t_object *obj);
void		set_copper_color(t_object *obj);
void		set_gold_color(t_object *obj);
void		set_tin_color(t_object *obj);
void		set_silver_color(t_object *obj);
void		set_emerald_color(t_object *obj);
void		set_jade_color(t_object *obj);
void		set_obsidian_color(t_object *obj);
void		set_perl_color(t_object *obj);
void		set_ruby_color(t_object *obj);
void		set_turquoise_color(t_object *obj);
void		set_black_plastic_color(t_object *obj);
void		set_cyan_plastic_color(t_object *obj);
void		set_green_plastic_color(t_object *obj);
void		set_red_plastic_color(t_object *obj);
void		set_white_plastic_color(t_object *obj);
void		set_yellow_plastic_color(t_object *obj);

double		double_min(double a, double b);
double		double_max(double a, double b);
int			int_min(int a, int b);
int			int_max(int a, int b);
double		double_window(double min, double max, double x);
int			int_window(int min, int max, int x);
t_vec3		ray2point(double length, t_ray ray);
t_rgb		render_pixel(t_vec3 pixel, double mat[3][3], t_miniRT minirt);
#endif
