/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:54:15 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 17:08:42 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	wrong_input(t_miniRT *minirt, int fd, char *str)
{
	close(fd);
	free_all(minirt);
	exit_err(str);
}

void	check_orient(t_vec3 orient, t_miniRT *minirt, int fd)
{
	if (orient.x > 1 || orient.x < -1
		|| orient.y > 1 || orient.y < -1
		|| orient.z > 1 || orient.z < -1)
		wrong_input(minirt, fd, "Out of orient vector range!");
	if (orient.x == 0 && orient.y == 0 && orient.z == 0)
		wrong_input(minirt, fd, "Wrong orient vector!");
}

void	check_rgb(t_rgb color, t_miniRT *minirt, int fd)
{
	if (color.r > 255 || color.r < 0
		|| color.g > 255 || color.g < 0
		|| color.b > 255 || color.b < 0)
		wrong_input(minirt, fd, "Out of rgb range!");
}
