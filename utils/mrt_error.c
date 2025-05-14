#include "../minirt.h"

void	args_num_err(int ac)
{
	if (ac < 2)
		ft_putstr_fd("please input .rt scene file\n", 2)
	else
		ft_putstr_fd("too many args\n", 2)
	exit (2);
}

void	file_err(int fd)
{
	if (fd == -2)
		ft_putstr_fd("please input a .rt file\n", 2);
	else
		perror("couldn't open file");
	exit(2);
}

void	inval_input(t_data *data, char *input)
{
	ft_putstr_fd("invalid input\n", 2);
	free_all(data);
	free(input);
	exit(2);
}

int	malloc_error(void)
{
	ft_putstr_fd("malloc failed\n", 2);
	return (1);
}

//error for multiple cam, ambiant, or lights in .rt file.
int	duplicate_error(int type, t_data *data)
{
	ft_putstr_fd("invalid input: ", 2);
	if (type == 1)
		ft_putstr_fd("more than one cam\n", 2);
	if (type == 2)
		ft_putstr_fd("more than one ambiant light\n", 2);
	if (type == 3)
		ft_putstr_fd("more than one light\n", 2);
	return (3);
}
