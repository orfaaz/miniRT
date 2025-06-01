#include "minirt.h"

void	check_collision(t_data *data, t_ray ray)
{
	t_color	color;



	put_pxl(x, y, color)
}

void	cast_ray(t_data *data, t_cam *cam, int u, int v)
{
	t_ray	ray;

	

	check_collision(data, ray);
}

void	display_scene(t_data *data)
{
	t_cam	*cam;
	int		u;
	int		v;

	u = 0;
	v = 0;
	cam->proj_screen = get_proj_screen(cam);//
	while (v < HEIGHT)
	{
		cast_ray(data, cam, u, v);
		if (u == WIDTH)
		{
			u = 0;
			v++;
		}
		u++;
	}
}
