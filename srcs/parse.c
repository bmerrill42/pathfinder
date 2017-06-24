#include "../includes/lem_in.h"

typedef struct s_node
{
	char *name;
	int index;
	int visited_p;
} t_node;

void store_room(char **line, t_lemin *everything)
{
	(void)everything;
	ft_putendl(*line);
}

int store_edge (char **line,  t_lemin *everything)
{
	(void)everything;
	ft_putendl(*line);
	return (1);
}

int set_start_room(t_lemin *everything)
{
	everything->start = everything->r_ct;
	return (1);
}

int set_end_room(t_lemin *everything)
{
	everything->end = everything->r_ct;
	return (1);
}


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
	while (ft_isprint(line[0][i]) && line[0][i] != ' ' && line [0][0] != 'L')
		i++;
	if (line[0][i] != ' ')
		return (0);
	else
		i++;
	while (ft_isdigit(line[0][i]))
		i++;
	if (line[0][i] != ' ')
		return (0);
	else
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
	while (is_comment(line))
		;
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		return (0);
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
		return (0);
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
		return (0);
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

int is_edge_list (char **line, t_lemin *everything)
{
	while (is_comment(line))
		;
	if (!is_edge(line, everything))
		return (0);
	while (is_edge(line, everything) || is_comment(line))
		;
	return (1);
}

int is_roomlist (char **line, t_lemin *everything)
{
	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
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
		throw_error(NO_START);
	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
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
		throw_error(NO_END);
	return (0);	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
	return (1);
}

int is_ant(char **line, t_lemin *everything)
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

int main()
{
	char *line;
	t_lemin everything;

	ft_bzero(&everything, sizeof(t_lemin));
	while (get_next_line(0, &line))
	{
		if (line == '\0')
			return (0);
		if (is_ant(&line, &everything))
			if (is_roomlist(&line, &everything))
				if (is_edge_list(&line, &everything))
				{
					free(line);
					get_next_line(-42, &line);
					return (1);
				}
				else
					return (0);
			else
				throw_error(NO_ROOMS);
		else
			throw_error(NO_ANTS);
	}
	return (0);
}
