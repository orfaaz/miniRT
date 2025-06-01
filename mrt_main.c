#include "minirt.h"

int	open_file(char *file)
{
	int	fd;

	fd = -2;
	if (ft_strrchr(file, ".rt\0"))
		fd = open(file, O_RDONLY);
	if (fd < 0)
		file_err(fd);
	return (fd);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac != 2)
		args_num_err(ac);
	fd = open_file(av[1]);
	data = parser(fd);
	data->win = set_win();
	display_scene(data);
	free_win(data);
}
