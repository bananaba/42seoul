#include "../includes/miniRT.h"

t_rgb	rgb_component_add(t_rgb rgb, t_rgb ratio)
{
	t_rgb	result;

    if (rgb.r + ratio.r > 255)
	    result.r = 255;
    else
    	result.r = rgb.r + ratio.r;
	if (rgb.g + ratio.g > 255)
	    result.g = 255;
	else
    	result.g = rgb.g + ratio.g;
	if (rgb.b + ratio.b > 255)
		result.b = 255;
	else
    	result.b = rgb.b + ratio.b;
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
