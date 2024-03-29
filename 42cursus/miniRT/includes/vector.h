/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:55:35 by balee             #+#    #+#             */
/*   Updated: 2023/02/18 02:26:26 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

//vector_util1
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
double	vec3_inner_pd(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross_pd(t_vec3 a, t_vec3 b);
t_vec3	vec3_scalar_mul(double scalar, t_vec3 a);

//vector_util2
t_vec3	vec3_normal(t_vec3 a);
double	vec3_norm(t_vec3 a);
double	vec3_ang_rad(t_vec3 a, t_vec3 b);
t_vec3	vec3_mat3_mul(double mat[3][3], t_vec3 a);
t_vec3	vec3_proj(t_vec3 a, t_vec3 b);

//vector_util3
t_vec3	vec3_component_mul(t_vec3 a, t_vec3 b);

#endif
