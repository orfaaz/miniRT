#include "../minirt.h"

t_vec	*set_vec(char **line)
{
	t_vec	*vec;
	
	vec = malloc(sizeof(t_vec));
	if (!vec)
		return (NULL);
	vec->x = atof(*line);
	while (**line && **line != ',')
		*line++;
	vec->y = atof(++*line);
	while (**line && **line != ',')
		*line++;
	vec->z = atof(++*line);
	while (**line && ft_isspace3(**line))
		*line++;
	return (vec);
}

t_color	*set_col(char **line)
{
	t_color	*col;
	
	col = malloc(sizeof(t_color));
	if (!col)
		return (NULL);
	col->x = atof(*line);//replace with atoi?
	while (**line && **line != ',')
		*line++;
	col->y = atof(++*line);
	while (**line && **line != ',')
		*line++;
	col->z = atof(++*line);
	while (**line && ft_isspace3(**line))
		*line++;
	return (col);
}

void	set_objects(t_data *data, char *line)
{
	int	err;

	err = 0;
	while (*line && ft_isspace3(*line))
		line++;
	//skip commented lines
	if (!ft_strchr("C", line))
		err = set_cam(data, line);
	if (!ft_strchr("A", line))
		err = set_amb(data, line);
	if (!ft_strchr("L", line))
		err = set_lgt(data, line);
	if (!ft_strchr("sp", line))
		set_sp(data, line);
	if (!ft_strchr("pl", line))
		set_pl(data, line);
	if (!ft_strchr("cy", line))
		set_cy(data, line);
	return (err);
}

//reads the .rt document, and sends the lines one by one
//to a ft storing the coordinates in a struct.
void	get_input(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (set_objects(data, line));//don't exit till gnl done;
		{
			free(line);
			free_all(data);
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (input);
}

t_data *parser(int fd)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_memset(data, 0);
	get_input(fd, data);
	close(fd);
	return (data);
}
