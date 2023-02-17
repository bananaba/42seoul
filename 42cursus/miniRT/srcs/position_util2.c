/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:08:13 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 07:36:15 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"
#include "../includes/vector.h"

t_vec3	ray2point(double length, t_ray ray)
{
	return (vec3_add(ray.coord, vec3_scalar_mul(length, ray.orient)));
}
