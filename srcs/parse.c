#include "../includes/lem_in.h"

typedef struct s_node
{
	char *name;
	int index;
	int visited_p;
} t_node;

int is_command(char *line)
{
	int i;

	i = 2;
	while (line[0] == '#' && line[1] == '#'	 && ft_isprint(line[i]))
		i++;
	if (line[i] != '\0')
		return (0);
	ft_putendl(line);
	return (1);
}

int is_comment(char **line)
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

int is_room(char **line, t_lemin *everything)
{
	int i;

	i = 0;
	while (ft_isprint(line[0][i]) && line[0][i] != ' ' && line [0][0] != 'L' &&
		   line[0][i] != '-')
		i++;
	if (line[0][i] != ' ')
		return (0);
	i++;
	if (line[0][i] == '-')
		i++;
	while (ft_isdigit(line[0][i]))
		i++;
	if (line[0][i] != ' ')
		return (0);
	i++;
	if (line[0][i] == '-')
		i++;
	while (ft_isdigit(line[0][i]))
		i++;
	if (!(line[0][i] == '\0'))
		return (0);
	store_room(line, everything);
	free(*line);
	get_next_line(0, line);
	return (1);
}

int is_start(char **line, t_lemin *everything)
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

int is_end(char **line, t_lemin *everything)
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

int extra_command(char **line, t_lemin *everything)
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

int is_edge(char **line,  t_lemin *everything)
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
	free(*line);
	get_next_line(0, line);
	return (1);
}

int main()
{
	char *line;
	t_lemin everything;
	int i;

	i = 0;
	ft_bzero(&everything, sizeof(t_lemin));
	while (get_next_line(0, &line))
	{
		if (line == '\0')
			return (0);
		if (!is_ant(&line, &everything))
			throw_error(NO_ANTS);
		if (!is_roomlist(&line, &everything))
			throw_error(GENERIC);
		if (!is_edge_list(&line, &everything))
			throw_error(GENERIC);
		return (1);
	}
	while (i < everything.r_ct)
		ft_putendl(everything.room_names[i++]);
	free(line);
	get_next_line(-42, &line);
	return (0);
}
