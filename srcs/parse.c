#include "../includes/lem_in.h"

int	is_comment(char **line)
{
	int i;

	i = 2;
	while (line[0][0] == '#' && line[0][1] != '#' && ft_isprint(line[0][i]))
		i++;
	if (line[0][0] == '#' && line[0][1] != '#' && line[0][i] == '\0')
	{
		ft_putendl(*line);
		free(*line);
		get_next_line(0, line);
		return (1);
	}
	else
		return (0);
}

int	is_dash_and_nspace(char **line, int *i)
{
	if (line[0][*i] != ' ')
		return (0);
	(*i)++;
	if (line[0][*i] == '-')
		(*i)++;
	return (1);
}

int	is_room(char **line, t_lemin *everything)
{
	int i;

	i = 0;
	while (ft_isprint(line[0][i]) && line[0][i] != ' ' && line[0][0] != 'L' &&
			line[0][i] != '-')
		i++;
	if (!is_dash_and_nspace(line, &i))
		return (0);
	while (ft_isdigit(line[0][i]))
		i++;
	if (!is_dash_and_nspace(line, &i))
		return (0);
	while (ft_isdigit(line[0][i]))
		i++;
	if (!(line[0][i] == '\0'))
		return (0);
	store_room(line, everything);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	return (1);
}

int	is_edge(char **line, t_lemin *everything)
{
	int i;

	i = 0;
	while (line[0][0] != '#' && ft_isprint(line[0][i]) && line[0][i] != '-')
		i++;
	if (line[0][i] != '-')
		return (0);
	i++;
	while (line[0][0] != '#' && ft_isprint(line[0][i]) && line[0][i] != '-')
		i++;
	if (line[0][0] != '#' && line[0][i] != '\0')
		return (0);
	store_edge(line, everything);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	return (1);
}

int	parse_input(t_lemin *everything)
{
	char	*line;
	int		i;

	i = 0;
	ft_bzero(everything, sizeof(t_lemin));
	while (get_next_line(0, &line))
	{
		if (line == '\0')
			return (0);
		if (!is_ant(&line, everything))
			throw_error(NO_ANTS);
		if (!is_roomlist(&line, everything))
			throw_error(GENERIC);
		if (!is_edge_list(&line, everything))
			throw_error(GENERIC);
		free(line);
		get_next_line(-42, &line);
		return (1);
	}
	if (line)
		free(line);
	get_next_line(-42, &line);
	return (0);
}
