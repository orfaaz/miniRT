
#ifndef MINIRT_H
# define MINIRT_H

# include <libft.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 600
# endif

//objects
//vector
typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

//color
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

//ray
typedef struct s_ray//normalise rays? 
{
	t_vec	*orig;
	t_vec	*dir;
}	t_ray;

//camera projection screen
typedef struct s_proj_screen
{
	int	length;//depends on fov?
	int	width;//width = WIDTH?
	int	ratio;//WIDTH/HEIGTH
}	t_proj_screen;//ints?

//3D objects
//camera
typedef struct s_cam
{
	t_vec	vtx;
	t_vec	rot;
	t_vec	up;//(0, 1, 0); can it be smth else?
	int		fov;
	int		far_clip;
	int		near_clip;
}	t_cam;//needs the img? (projection grid)

//ambiant light
typedef struct s_amb
{
	float	i;
	t_color	color;
}	t_amb;

//point light
typedef struct s_lgt
{
	t_vec	vtx;
	float	i;
	t_color	color;
}	t_lgt;

//cone light
// typedef struct s_c_lgt
// {
// 	t_vec	vtx;
// 	t_vec	rot;
// 	float	cone;
// 	float	i;
// 	t_color	color;
// }	t_c_lgt;

//plane
typedef struct s_pl
{
	t_vec	vtx;
	t_vec	rot;
	t_color	color;
}	t_pl;

//sphere
typedef struct s_sp
{
	t_vec	vtx;
	float	d;
	t_color	color;
}	t_sp;

//cylinder
typedef struct s_cy
{
	t_vec	vtx;
	t_vec	rot;
	float	d;
	float	h;
	t_color	color;
}	t_cy;

//Mlx structs.
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		line_len;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_transform	*trsfm;
}	t_win;

//main structs
typedef struct s_data
{
	t_cam	*cam;
	t_amb	*amb;
	t_lgt	*lgt;
	t_sp	*sp_lst;
	t_pl	*pl_lst;
	t_cy	*cy_lst;
	t_win	*win;
}	t_data;

#endif
