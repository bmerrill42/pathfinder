#include "../includes/lem_in.h"

int	is_command(char *line)
{
	int i;

	i = 2;
	while (line[0] == '#' && line[1] == '#' && ft_isprint(line[i]))
		i++;
	if (line[i] != '\0')
		return (0);
	ft_putendl(line);
	return (1);
}

int	is_start(char **line, t_lemin *everything)
{
	if (ft_strcmp(*line, "##start"))
		return (0);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		throw_error(BAD_ROOM_NAME);
	set_start_room(everything);
	return (1);
}

int	is_end(char **line, t_lemin *everything)
{
	if (ft_strcmp(*line, "##end"))
		return (0);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		throw_error(BAD_ROOM_NAME);
	set_end_room(everything);
	return (1);
}

int	extra_command(char **line, t_lemin *everything)
{
	if (!ft_strcmp(*line, "##end") || !ft_strcmp(*line, "##start"))
		return (0);
	if (!is_command(*line))
		return (0);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		throw_error(BAD_ROOM_NAME);
	return (1);
}
