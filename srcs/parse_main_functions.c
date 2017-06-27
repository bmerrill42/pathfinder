#include "../includes/lem_in.h"

int	is_edge_list (char **line, t_lemin *everything)
{
	while (is_comment(line))
		;
	if (!is_edge(line, everything))
		return (0);
	while (is_edge(line, everything) || is_comment(line))
		;
	return (1);
}

void	start_or_end(char **line, t_lemin *everything)
{
	if (!ft_strcmp("##start", *line))
	{
		if (!is_start(line, everything))
			throw_error(NO_START);
	}
	else if (!ft_strcmp("##end", *line))
	{
		if (!is_end(line, everything))
			throw_error(NO_END);
	}
	else
		throw_error(GENERIC);
}

int	is_roomlist(char **line, t_lemin *everything)
{
	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
		start_or_end(line, everything);
	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
		start_or_end(line, everything);
	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
	return (1);
}

int	is_ant(char **line, t_lemin *everything)
{
	int i;

	i = 0;
	while (is_comment(line))
		;
	while (ft_isdigit(line[0][i++]))
		;
	if (line[0][i] != '\0')
		return(0);
	everything->ant_count = ft_atoi(*line);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	return (1);
}
