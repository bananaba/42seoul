#include "../includes/miniRT.h"

void	setCameraRay(t_vec3 *ray, t_camera camera)
{
	double	mat[3][3];

    mat[0][2] = camera.orient.x;
	mat[1][2] = camera.orient.y;
	mat[2][2] = camera.orient.z;
	if (ray->x == 0 && ray->z == 0)
	{
		mat[0][0] = 1;
		mat[1][0] = 0;
		mat[2][0] = 0;
		mat[0][1] = 0;
		mat[1][1] = 1;
		mat[2][1] = -camera.orient.y;
    }
	else
	{
		// mat[0][0] = camera.orient.z;
		// mat[1][0] = 0;
		// mat[2][0] = -camera.orient.x;
		mat[0][1] = camera.orient.y * mat[2][0] - camera.orient.z * mat[1][0];
		mat[1][1] = camera.orient.z * mat[0][0] - camera.orient.x * mat[2][0];
		mat[2][1] = camera.orient.x * mat[1][0] - camera.orient.y * mat[0][0];
	}
}

int	draw(t_miniRT miniRT)
{
	t_vec3	ray;
	double	d;
	double	h;
	double	w;

	d = (WIDTH / 2) / tan(miniRT.camera.fov / 2);
	h = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
        {
			ray.x = w - (WIDTH / 2);
			ray.y = (HEIGHT / 2) - h;
			ray.z = d;
			setCameraRay(&ray, miniRT.camera);
		}
	}
}
