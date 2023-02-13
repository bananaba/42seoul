/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:57:07 by balee             #+#    #+#             */
/*   Updated: 2023/02/13 22:50:03 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	check_extention(char *file)
{
	while (*file != '\0')
		file++;
	file -= 3;
	if (ft_strncmp(file, ".rt", 3) != 0)
		exit_err();
}

int	file_len(int fd)
{
	char	c;
	int		len;

	len = 0;
	while (read(fd, &c, 1))
		len++;
	close (fd);
	return (len);
}

void	read_map(t_miniRT *minirt, int fd, char *file)
{
	char	*temp;
	int		len;

	len = file_len(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_err();
	minirt->str = (char *)malloc(sizeof(char) * (len + 1));
	if (minirt->str == NULL)
		exit_err();
	read(fd, minirt->str, len);
	minirt->str[len] = '\0';
	temp = minirt->str;
	while (*temp)
	{
		if (*temp == 'A')
			get_ambient_light(minirt, &temp);
		else if (*temp == 'C')
			get_camera(minirt, &temp);
		else if (*temp == 'L')
			get_light(minirt, &temp);
		else
			get_objects(minirt, &temp);
	}
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
		exit_err();
	read_map(minirt, fd, file);
	if ((minirt->checker & 0x11) != 0x11)
		exit_err();
	img = &minirt->img;
	minirt->mlx = mlx_init();
	img->img = mlx_new_image(minirt->mlx, WIDTH, HEIGHT);
	img->canvas = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);
	minirt->win = mlx_new_window(minirt->mlx, WIDTH, HEIGHT, "miniRT");
	close(fd);
}
