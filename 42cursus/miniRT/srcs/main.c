/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:36:08 by balee             #+#    #+#             */
/*   Updated: 2023/02/12 21:23:09 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	init_miniRT(t_miniRT *miniRT)
{
	t_img	*img;

	img = &miniRT->img;
	miniRT->mlx = mlx_init();
	img->img = mlx_new_image(miniRT->mlx, WIDTH, HEIGHT);
	img->canvas = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);
	miniRT->win = mlx_new_window(miniRT->mlx, WIDTH, HEIGHT, "miniRT");
}

int	main(void)
{
	t_miniRT	minirt;

	minirt.alight.r = 176 * 1.0;
	minirt.alight.g = 205 * 1.0;
	minirt.alight.b = 255 * 1.0;
	minirt.camera.coord.x = -60;
	minirt.camera.coord.y = 0;
	minirt.camera.coord.z = 0;
	minirt.camera.orient.x = 1;
	minirt.camera.orient.y = 0;
	minirt.camera.orient.z = 0;
	minirt.camera.fov = 90;
	minirt.lights = (t_list *)malloc(sizeof(t_list));
	minirt.lights->content = (t_light *)malloc(sizeof(t_light));
	minirt.lights->next = NULL;
	((t_light *)minirt.lights->content)->coord.x = 0;
	((t_light *)minirt.lights->content)->coord.y = 300;
	((t_light *)minirt.lights->content)->coord.z = -50;
	((t_light *)minirt.lights->content)->rgb.r = 255 * 0.0;
	((t_light *)minirt.lights->content)->rgb.g = 255 * 0.6;
	((t_light *)minirt.lights->content)->rgb.b = 255 * 0.0;
	minirt.lights->next = (t_list *)malloc(sizeof(t_list));
	minirt.lights->next->content = (t_light *)malloc(sizeof(t_light));
	minirt.lights->next->next = NULL;
	((t_light *)minirt.lights->next->content)->coord.x = 0;
	((t_light *)minirt.lights->next->content)->coord.y = 300;
	((t_light *)minirt.lights->next->content)->coord.z = 50;
	((t_light *)minirt.lights->next->content)->rgb.r = 255 * 0.6;
	((t_light *)minirt.lights->next->content)->rgb.g = 255 * 0.0;
	((t_light *)minirt.lights->next->content)->rgb.b = 255 * 0.6;
	minirt.objects = (t_list *)malloc(sizeof(t_list));
	minirt.objects->content = (t_object *)malloc(sizeof(t_object));
	minirt.objects->next = NULL;
	((t_object *)minirt.objects->content)->coord.x = 10;
	((t_object *)minirt.objects->content)->coord.y = 0;
	((t_object *)minirt.objects->content)->coord.z = 0;
	((t_object *)minirt.objects->content)->type = 'S';
	((t_object *)minirt.objects->content)->shininess = 11;
	((t_object *)minirt.objects->content)->ambient.r = 0.25;
	((t_object *)minirt.objects->content)->ambient.g = 0.20;
	((t_object *)minirt.objects->content)->ambient.b = 0.20;
	((t_object *)minirt.objects->content)->diffuse.r = 1;
	((t_object *)minirt.objects->content)->diffuse.g = 0.83;
	((t_object *)minirt.objects->content)->diffuse.b = 0.83;
	((t_object *)minirt.objects->content)->specular.r = 0.29;
	((t_object *)minirt.objects->content)->specular.g = 0.29;
	((t_object *)minirt.objects->content)->specular.b = 0.29;
	((t_object *)minirt.objects->content)->info = (t_sphere *)malloc(sizeof(t_sphere));
	((t_sphere *)((t_object *)minirt.objects->content)->info)->radius = 10;
	minirt.objects->next = (t_list *)malloc(sizeof(t_list));
	minirt.objects->next->content = (t_object *)malloc(sizeof(t_object));
	minirt.objects->next->next = NULL;
	((t_object *)minirt.objects->next->content)->coord.x = 0;
	((t_object *)minirt.objects->next->content)->coord.y = -20;
	((t_object *)minirt.objects->next->content)->coord.z = 0;
	((t_object *)minirt.objects->next->content)->type = 'P';
	((t_object *)minirt.objects->next->content)->shininess = 32;
	((t_object *)minirt.objects->next->content)->ambient.r = 0.5;
	((t_object *)minirt.objects->next->content)->ambient.g = 0.5;
	((t_object *)minirt.objects->next->content)->ambient.b = 0.5;
	((t_object *)minirt.objects->next->content)->diffuse.r = 0.55;
	((t_object *)minirt.objects->next->content)->diffuse.g = 0.55;
	((t_object *)minirt.objects->next->content)->diffuse.b = 0.55;
	((t_object *)minirt.objects->next->content)->specular.r = 0.1;
	((t_object *)minirt.objects->next->content)->specular.g = 0.1;
	((t_object *)minirt.objects->next->content)->specular.b = 0.1;
	((t_object *)minirt.objects->next->content)->info = (t_plane *)malloc(sizeof(t_plane));
	((t_plane *)((t_object *)minirt.objects->next->content)->info)->normal.x = 0;
	((t_plane *)((t_object *)minirt.objects->next->content)->info)->normal.y = 1;
	((t_plane *)((t_object *)minirt.objects->next->content)->info)->normal.z = 0;
	init_miniRT(&minirt);
	draw(minirt);
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img.img, 0, 0);
	mlx_loop(minirt.mlx);
	return (0);
}
