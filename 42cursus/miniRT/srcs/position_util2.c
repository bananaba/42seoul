/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:08:13 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 17:24:24 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	ray2point(double length, t_ray ray)
{
	return (vec3_add(ray.coord, vec3_scalar_mul(length, ray.orient)));
}
