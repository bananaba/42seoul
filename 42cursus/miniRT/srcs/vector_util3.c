/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:37:14 by balee             #+#    #+#             */
/*   Updated: 2023/02/16 19:40:25 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	vec3_proj(t_vec3 a, t_vec3 b)
{
	t_vec3	result;
	double	k;

	k = vec3_inner_pd(a, b) / pow(vec3_norm(a), 2);
	result = vec3_scalar_mul(k, a);
	return result;
}
