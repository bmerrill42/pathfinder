#include "../libft/libft.h"

typedef struct s_node
{
	char *name;
	int index;
	int visited_p;
} t_node;

typedef struct s_all
{
	t_node *node_arr;
	int start_index;
	int end_index;
	int size;
	int num_of_ants;
	int **connection_table;
	int node_count;
} t_all;

int is_command(char *line)
{
	int i;

	i = 2;
	while (line[0] == '#' && line[1] == '#'  && ft_isprint(line[i]))
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

void store_room(char **line, t_all *everything)
{
	/*
	**do something fancy storing the node in the node array
	*/
	(void)everything;
	ft_putendl(*line);
}

int is_room(char **line, t_all *everything)
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

int set_start_room(t_all *everything)
{

	everything->start_index = everything->size;
	return (1);
}

int set_end_room(t_all *everything)
{
	everything->end_index = everything->size;
	return (1);
}

int is_start(char **line, t_all *everything)
{
	if (ft_strcmp(*line, "##start"))
		return (0);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		return (0);
	set_start_room(everything);
	return (1);
}

int is_end(char **line, t_all *everything)
{
	if (ft_strcmp(*line, "##end"))
		return (0);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		return (0);
	set_end_room(everything);
	free(*line);
	get_next_line(0, line);
	return (1);
}

int extra_command(char **line, t_all *everything)
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

int store_edge (char **line,  t_all *everything)
{
	(void)everything;
	ft_putendl(*line);
	return (1);
}

int is_edge(char **line,  t_all *everything)
{
	int i;

	i = 0;
	while (line[0][0] != '#' && ft_isprint(line[0][i]))
		i++;
	if (line[0][i] != '-')
		return (0);
	while (line[0][0] != '#' && ft_isprint(line[0][i]))
		i++;
	if (line[0][0] != '#' && line[0][i] != '\0')
		return (0);
	ft_putendl(*line);
	store_edge(line, everything);
	free(*line);
	get_next_line(0, line);
	return (1);
}

int is_edge_list (char **line, t_all *everything)
{
	while (is_comment(line))
		;
	if (!is_edge(line, everything))
		return (0);
	while (is_edge(line, everything) || is_comment(line))
		;
	return (1);
}

int is_roomlist (char **line, t_all *everything)
{
	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
	if (!is_start(line, everything))
		return (0);
	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
	if (!is_end(line, everything))
		return (0);
	while (is_comment(line) || is_room(line, everything) || extra_command(line, everything))
		;
	return (1);
}

int is_ant(char **line, t_all *everything)
{
	int i;

	i = 0;
	while (is_comment(line))
		;
	while (ft_isdigit(line[0][i++]))
		;
	if (line[0][i] == '\0')
	{
		everything->num_of_ants = ft_atoi(*line);
		ft_putendl(*line);
		free(*line);
		get_next_line(0, line);
		return (1);
	}
	else
		return(0);
}

int main()
{
	char *line;
	t_all everything;

	ft_bzero(&everything, sizeof(t_all));
	/*
	**parse the file with my best approximation of recursive descent
	*/
	while (get_next_line(0, &line))
	{
		if (line == '\0')
			return (0);
		if (is_ant(&line, &everything))
			if (is_roomlist(&line, &everything))
				if (is_edge_list(&line, &everything))
					return (1);
				else
					return (0);
			else
				return (0);
		else
			return (0);
	}
	return (0);
}
