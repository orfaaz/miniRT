#include "minirt.h"

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
