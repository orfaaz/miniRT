#include "minirt.h"

//mlx intialisation
t_win	*set_win(void)
{
	t_win	*win;
	t_img	*img;

	win = malloc(sizeof(t_win));
	img = malloc(sizeof(t_img));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "fdf");
	img->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	win->img = img;
	return (win);
}

//unsets mlx and frees everything.
void	free_win(t_data *data)
{
	t_win	*win;
	t_img	*img;

	win = data->win;
	img = win->img;
	mlx_destroy_image(win->mlx, img->img);
	free(img);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	free(win);
	// dbarr_free((void **)map->map);
	// dbarr_free((void **)map->isomap);
	// free(map->trsfm);
	// free(map);
}

//put pixel
//one ray per pixel. it will give a color for each
void	put_pxl(t_img *img, t_isovtx *vtx, unsigned int color)
{
	char	*dst;

	if (vtx->y >= 0 && vtx->y < HEIGHT
		&& vtx->x >= 0 && ft_round(vtx->x) < WIDTH)
	{
		dst = img->addr + (ft_round(vtx->y) * img->line_len
				+ ft_round(vtx->x) * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

//blacks out screen before drawing on it again.
void	screen_reset(t_img *img)
{
	t_isovtx	black;
	int			i;

	i = -1;
	black.y = -1;
	black.x = -1;
	while (++i < HEIGHT * WIDTH)
	{
		black.x++;
		if (i % WIDTH == 0)
		{
			black.y++;
			black.x = 0;
		}
		put_pxl(img, &black, 0);
	}
}

//hooks & events vvv
int	no_event(void *data)
{
	(void)data;
	return (0);
}

//breaking out of the mlx loop.
int	close_win(t_win *win)
{
	mlx_loop_end(win->mlx);
	return (0);
}

//modifies t_transforms values according to the input.
void	transform(t_win *win, char c)
{
	t_map		*map;
	t_transform	*trsfm;

	map = win->map;
	trsfm = win->trsfm;
	if (c == 'l')//example
		trsfm->tx -= 3;
	display(map, win);
}

//checks inputs, and rederects to the according functions.
int	hook_parser(int keysym, void *data)
{
	t_win		*win;
	t_transform	*trsfm;

	win = (t_win *)data;
	trsfm = win->trsfm;
	if (keysym == XK_Escape)
		close_win(win);
	else if (keysym == XK_Left)//example
		transform(win, 'l');
	return (0);
}
