#include "minirt.h"

void	check_collision(t_data *data, t_ray ray)
{
	t_color	color;



	put_pxl(x, y, color)
}

void	trace_ray(t_data *data, t_cam *cam, int u, int v)
{
	t_ray	ray;

	

	check_collision(data, ray);
}

//links a screen pxl to a viewport pxl/ray.
t_vec	*screen_to_vp(int x, int y)
{
	t_vec	*vp_pxl;
 
	vp_pxl->x = x * (WIDTH / );
	vp_pxl->y = y * (HEIGHT / );
	vp_pxl->z = cam->fl;//focal length
	return (vp_pxl);
}

void	display_scene(t_data *data)
{
	t_cam	*cam;
	int		u;
	int		v;

	u = 0;
	v = 0;
	while (v < HEIGHT)
	{
		trace_ray(data, cam, u, v);
		if (u == WIDTH)
		{
			u = 0;
			v++;
		}
		u++;
	}
}
