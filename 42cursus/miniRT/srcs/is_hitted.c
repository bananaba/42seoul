#include "../includes/miniRT.h"

double	sphere_hitted(t_object *object, t_ray ray)
{
	double	d;
	double	k;

	d = vec3_norm(vec3_cross_pd(vec3_sub(object->coord, ray.coord), ray.orient))
		/ vec3_norm(ray.orient);
	if (((t_sphere *)object->info)->radius < d)
		return (0);
	k = get_k(object, ray);
	if (k <= 0)
		return (0);
	return (k);
}

double	plane_hitted(t_object *object, t_ray ray)
{
	double	k;

	if (vec3_inner_pd(ray.orient, ((t_plane *)object->info)->normal) == 0)
	    return (0);
	k = get_k(object, ray);
	if (k <= 0)
		return (0);
	return (k);
}

double	check_hitted(t_object *object, t_ray ray)
{
	if (object->type == 'S')
		return (sphere_hitted(object, ray));
	else if (object->type == 'P')
		return (plane_hitted(object, ray));
}

int	is_hitted(t_miniRT miniRT, t_ray ray, int n)
{
	t_list	*object;
	int		i;
	int		hit;
	double	k;
	double	temp;

	object = miniRT.objects;
	i = 1;
	hit = 0;
	while (object != NULL)
	{
		if (i != n)
		{
			temp = check_hitted(object->content, ray);
			if (temp != 0 && (hit == 0 || k > temp))
			{
				hit = i;
				k = temp;
			}
		}
		i++;
		object = object->next;
	}
	return (hit);
}
