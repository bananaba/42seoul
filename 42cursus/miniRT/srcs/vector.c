/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:18:35 by snoh              #+#    #+#             */
/*   Updated: 2023/01/30 02:35:15 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../includes/miniRT.h"

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3 result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3 result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

double	vec3_inner_pd(t_vec3 a, t_vec3 b)
{
	double result;

	result = 0.0;
	result += a.x * b.x;
	result += a.y * b.y;
	result += a.z * b.z;

	return (result);
}

t_vec3	vec3_cross_pd(t_vec3 a, t_vec3 b)
{
    t_vec3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

t_vec3	vec3_scalar_mul(double scalar, t_vec3 a)
{
	t_vec3 result;

	result.x = scalar * a.x;
	result.y = scalar * a.y;
	result.z = scalar * a.z;
	return (result);
}

double	vec3_norm(t_vec3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec3	vec3_unit(t_vec3 a)
{
	return (scalar_mul_vec3(1.0 / norm_vec3(a)), a);
}

double vec3_ang_rad(t_vec3 a, t_vec3 b)
{
    double dot_product = vec3_inner_pd(a, b);
	double norm_product = vec3_norm(a) * vec3_norm(b);
    return (acos(dot_product / norm_product));
}

double vec3_ang_deg(t_vec3 a, t_vec3 b)
{
    double dot_product = vec3_inner_pd(a, b);
    double norm_product = vec3_norm(a) * vec3_norm(b);
    double angle_rad = acos(dot_product / norm_product);
    return (angle_rad * 180.0 / M_PI);
}
