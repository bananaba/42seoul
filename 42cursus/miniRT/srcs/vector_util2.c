/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:18:35 by snoh              #+#    #+#             */
/*   Updated: 2023/02/17 13:43:46 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	vec3_normal(t_vec3 a)
{
	t_vec3	result;
	double	len;

	len = sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
	result.x = a.x / len;
	result.y = a.y / len;
	result.z = a.z / len;
	return (result);
}

double	vec3_norm(t_vec3 a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

double	vec3_ang_rad(t_vec3 a, t_vec3 b)
{
	double	dot_product;
	double	norm_product;

	dot_product = vec3_inner_pd(a, b);
	norm_product = vec3_norm(a) * vec3_norm(b);
	return (acos(dot_product / norm_product));
}

t_vec3	vec3_mat3_mul(double mat[3][3], t_vec3 a)
{
	t_vec3	result;

	result.x = a.x * mat[0][0] + a.y * mat[1][0] + a.z * mat[2][0];
	result.y = a.x * mat[0][1] + a.y * mat[1][1] + a.z * mat[2][1];
	result.z = a.x * mat[0][2] + a.y * mat[1][2] + a.z * mat[2][2];
	return (result);
}

t_vec3	vec3_proj(t_vec3 a, t_vec3 b)
{
	t_vec3	result;
	double	k;

	k = vec3_inner_pd(a, b) / pow(vec3_norm(a), 2.0);
	result = vec3_scalar_mul(k, a);
	return (result);
}
