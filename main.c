#include "libft/libft.h"

typedef struct s_node
{
	char *name;
	int index;
	int visited_p;
} t_node;

typedef struct s_all
{
	t_node *node_arr;
	t_node start;
	t_node end;
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
	if (line[i] == '\0')
		return (1);
	else
		return (0);
}

int is_comment(char **line)
{
	int i;

	i = 2;
	while (line[0][0] == '#' && line[0][1] != '#'  && ft_isprint(line[0][i]))
		i++;
	if (line[0][i] == '\0')
	{
		ft_putendl(*line);
		free(*line);
		get_next_line(0, line);
		return (1);
	}
	else
		return (0);

}

void store_room(char **line)
{
	/*
	**do something fancy storing the node in the node array
	*/
	ft_putendl(*line);
}

int is_room(char **line)
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
	if (!line[0][i] == '\0')
		return (0);
	store_room(line);//, everything);
	free(*line);
	get_next_line(0, line);
	return (1);
}

int is_start(char **line)
{
	if (!ft_strcmp(*line, "##start"))
	{
		free(*line);
		get_next_line(0, line);
		if (is_room(line))
		{

//			set_start_room(line, everything);
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);

}

int is_end(char **line)
{
	if (ft_strcmp(*line, "##end"))
	{
		free(*line);
		get_next_line(0, line);
		if (is_room(line))
		{
			set_end_room(line, everything);
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);

}

/* int check_command(char *line) */
/* { */
/* 	int i; */
/* 	char **commands; */

/* 	i = 0; */
/* 	commands = (char **)malloc(sizeof(char*) * 3); */
/* 	commands[0] = ft_strdup("##yes"); */
/* 	commands[1] = ft_strdup("##indeed"); */
/* 	commands[2] = ft_strdup("##butts"); */
/* 	while (ft_strcmp(commands[i], line[0]) != 0 && i < 3) */
/* 		i++; */
/* 	if (i == 3) */
/* 		return (0); */
/* 	else */
/* 	{ */
/* 		ft_putendl(line); */
/* 		return (1); */
/* 	} */
/* } */

/* void handle_command(char *line) */
/* { */
/* 	ft_putendl(line); */
/* } */

int command_work( )
{
}

int is_roomlist(char **line, t_all *everything)
{
	while (is_comment(line) || is_room(line) || command_work(line))
		;
	if (!is_start(line[0]))
		return (0);
	while (is_comment(line) || is_room(line) || command_work(line))
		;
	if (!is_end(line[0]))
		return (0);
	while (is_comment(line) || is_room(line) || command_work(line))
		;
	if (is_edge)
		return (1);
	else
		return (0);
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
		if (is_ant(&line, &everything))
			if (is_roomlist(&line, &everything))
				;
//		while (is_edge_list(line, &everything))
//		 	get_next_line(0, &line);
		if (!*line)
		{
//			throw_error();
			return (0);
		}
	}
	return (0);
}
