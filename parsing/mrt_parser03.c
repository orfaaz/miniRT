#include "../minirt.h"

void	set_sp(t_data *data, char *line)
{
	t_sp	*sp;

	sp = sp_lstnew();
	while (*line && !ft_isspace3(*line))
		line++;
	while (*line && ft_isspace3(*line))
		line++;
	sp->vtx = set_vec(line);
	sp->d = ft_atof(line);//atoi?
	sp->col = set_col(line);
	ft_lstad_back(&data->sp, sp);
}

void	set_pl(t_data *data, char *line)
{
	t_pl	*pl;

	pl = pl_lstnew();
	while (*line && !ft_isspace3(*line))
		line++;
	while (*line && ft_isspace3(*line))
		line++;
	pl->vtx = set_vec(line);
	pl->rot = set_vec(line);
	pl->col = set_col(line);
	ft_lstad_back(&data->pl, pl);
}

void	set_cy(t_data *data, char *line)
{
	t_cy	*cy;

	cy = cy_lstnew();
	while (*line && !ft_isspace3(*line))
		line++;
	while (*line && ft_isspace3(*line))
		line++;
	cy->vtx = set_vec(line);
	cy->rot = set_vec(line);
	cy->d = ft_atof(line);
	while (*line && !ft_isspace3(*line))
		line++;
	while (*line && ft_isspace3(*line))
		line++;
	cy->h = ft_atof(line);
	while (*line && !ft_isspace3(*line))
		line++;
	while (*line && ft_isspace3(*line))
		line++;
	cy->col = set_col(line);
	ft_lstad_back(&data->cy, cy);
}

//void	set_dirlight(char *line)
