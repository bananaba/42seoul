/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:57:07 by balee             #+#    #+#             */
/*   Updated: 2023/02/18 21:02:23 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	check_extention(char *file)
{
	while (*file != '\0')
		file++;
	file -= 3;
	if (ft_strncmp(file, ".rt", 3) != 0)
		exit_err("Undefined extention of map file!");
}

void	read_map(t_miniRT *minirt, int fd)
{
	char	c;

	while (read(fd, &c, 1))
	{
		if (c == 'A')
			get_ambient_light(minirt, fd);
		else if (c == 'C')
			get_camera(minirt, fd);
		else if (c == 'L')
			get_light(minirt, fd);
		else if (!(c == '\n' || c == ' ' || (c >= 0x9 && c <= 0xd)))
			get_objects(minirt, fd, c);
	}
	close(fd);
}

void	init_minirt(t_miniRT *minirt, char *file)
{
	t_img	*img;
	int		fd;

	minirt->checker = 0;
	minirt->lights = NULL;
	minirt->objects = NULL;
	check_extention(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_err("Map file open fail!");
	read_map(minirt, fd);
	if (!(minirt->checker & 0x11))
		wrong_input(minirt, fd, "No ambient light or no camera!");
	check_camera_pos(minirt, minirt->camera, minirt->objects);
	img = &minirt->img;
	minirt->mlx = mlx_init();
	img->img = mlx_new_image(minirt->mlx, WIDTH, HEIGHT);
	img->canvas = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->size_line, &img->endian);
	minirt->win = mlx_new_window(minirt->mlx, WIDTH, HEIGHT, "miniRT");
	close(fd);
}
