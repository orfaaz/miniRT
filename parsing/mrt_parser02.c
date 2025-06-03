#include "../minirt.h"

t_viewport	*set_viewport()
{
	t_viewport	*viewport;

	viewport = malloc((sizeof)t_viewport);
	if (!viewport)
		return (NULL);//exit?
	viewport->width = WIDTH;//wrong
	viewport->ratio = WIDTH / HEIGHT;
	viewport->length = 1;//depend du fov
	viewport->pxl_tab = malloc((sizeof)t_vec * ((WIDTH * HEIGHT) + 1));
}

int	set_cam(t_data *data, char *line)
{
	t_cam	*cam;

	if (data->cam)
		return (duplicate_error(1));
	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (malloc_error());
	data->cam = cam;
	while (*line && !ft_isspace3(*line))
		line++;
	while (*line && ft_isspace3(*line))
		line++;
	cam->vtx = set_vec(line);
	cam->rot = set_vec(line);
	cam->up = set_vec("0.0, 1.0, 0.0");
	cam->viewport = set_viewport();
	cam->fov = ft_atof(line);
	return (0);
}

int	set_amb(t_data *data, char *line)
{
	t_amb	*amb;

	if (data->amb)
		return (duplicate_error(2));
	amb = malloc(sizeof(t_amb));
	if (!amb)
		return (malloc_error());
	data->amb = amb;
	while (*line && !ft_isspace3(*line))
		line++;
	while (*line && ft_isspace3(*line))
		line++;
	amb->i = ft_atof(line);
	amb->col = set_col(line);
	return (0);
}

int	set_light(t_data *data, char *line)
{
	t_lgt	*light;

	if (data->lgt)
		return (duplicate_error(3));
	light = malloc(sizeof(t_lgt));
	if (!light)
		return (malloc_error());
	data->lgt = light;
		while (*line && !ft_isspace3(*line))
		line++;
	while (*line && ft_isspace3(*line))
		line++;
	light->vtx = set_vec(line);
	light->i = ft_atof(line);
	light->col = set_col(line);
	return (0);
}
