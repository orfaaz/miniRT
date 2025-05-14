#include "../minirt.h"

void	free_lst(void *lst)
{
	void	*tmp;

	tmp = lst;
	while (lst)
	{
		free(tmp);
		lst = lst->next;
		tmp = lst;
	}
}

void	free_all(t_data *data)
{
	t_win	*win;
	t_img	*img;

	destroy_img;
	gestroy_win;
	free(data->cam);
	free(data->amb);
	free(data->lgt);
	free_lst(data->sp_lst);
	free_lst(data->pl_lst);
	free_lst(data->cy_lst);
}

float	ft_atof(char *str)
{
	float	ret;
	int		i;

	ret = 0;
	i = 10;
	while (*str && ft_isdigit(*str))
	{
		ret = ret * 10 + (*str - 48);
		str++;
	}
	if (*str != '.')
		return (ret);
	str++;
	while (*str && ft_isdigit(*str))
	{
		ret = ret + ((*str - 48) / i);
		i += 10;
		str++;
	}
	return (ret);
}
