/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_util1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:32:17 by balee             #+#    #+#             */
/*   Updated: 2023/02/12 19:53:50 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_rgb	rgb_component_add(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	result;

	result.r = rgb1.r + rgb2.r;
	result.g = rgb1.g + rgb2.g;
	result.b = rgb1.b + rgb2.b;
	return (result);
}

t_rgb	rgb_component_mul(t_rgb rgb, t_rgb ratio)
{
	t_rgb	result;

	result.r = rgb.r * ratio.r;
	result.g = rgb.g * ratio.g;
	result.b = rgb.b * ratio.b;
	return (result);
}

t_rgb	rgb_scalar_mul(t_rgb rgb, double ratio)
{
	t_rgb	result;

	result.r = rgb.r * ratio;
	result.g = rgb.g * ratio;
	result.b = rgb.b * ratio;
	return (result);
}
