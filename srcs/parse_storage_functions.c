#include "../includes/lem_in.h"

void new_str_array(char *str, t_room **rooms)
{
	(*rooms) = (t_room *)ft_memalloc(sizeof(t_room));
	(*rooms)[0].name = ft_strdup(str);
	rooms[0]->start = FALSE;
	rooms[0]->end = FALSE;
	rooms[0]->visited = FALSE;
	rooms[0]->connections = NULL;
}

void add_to_str_array(char *str, t_room **rooms)
{
	t_room *tmp;
	int i;

	i = 0;
	tmp = (t_room *)ft_memalloc(sizeof(*rooms) + sizeof(t_room));
	while (i < (int)(sizeof(*rooms) / sizeof(t_room*)))
	{
		tmp[i].name = ft_strdup((*rooms)[i].name);
		tmp[i].start = FALSE;
		tmp[i].end = FALSE;
		tmp[i].visited = FALSE;
		tmp[i].connections = NULL;
		i++;
	}
	tmp[i].start = FALSE;
	tmp[i].end = FALSE;
	tmp[i].visited = FALSE;
	tmp[i].connections = NULL;
	tmp[i].name = ft_strdup(str);
	free(*rooms);
	(*rooms) = tmp;
}

void store_room(char **line, t_lemin *everything)
{
	if (!everything->rooms->name)
		new_str_array(*line, &everything->rooms);
	else
		add_to_str_array(*line, &everything->rooms);
	everything->r_ct++;
}

void new_int_array(t_room *room, int neighbor)
{
	room->connections = (int*)malloc(sizeof(int));
	room->connections[0] = neighbor;
}

void add_int_array(t_room *room, int neighbor)
{
	int *tmp;
int i;

i = 0;
	tmp = (int*)malloc(room->c_count * sizeof(int));
	while (i < room->c_count)
	{
		tmp[i] = room->connections[i];
		i++;
	}
	tmp[i] = neighbor;
	free(room->connections);
	room->connections = tmp;
}

void add_connection(t_lemin *everything, int room, int neighbor)
{
	if (!everything->rooms[room].connections)
		new_int_array(&everything->rooms[room], neighbor);
	else
		add_int_array(&everything->rooms[room], neighbor);
	everything->rooms[room].c_count++;
}

void store_edge (char **line,  t_lemin *everything)
{
	char **tmp;
int i;
int first_match;
int second_match;

i = 0;
	tmp = ft_strsplit(*line, '-');
	while (!ft_strstr(everything->rooms[i].name, tmp[0]))
		i++;
	first_match = i;
	i = 0;
	while (!ft_strstr(everything->rooms[i].name, tmp[1]))
		i++;
	second_match = i;
	add_connection(everything, first_match, second_match);
	add_connection(everything, second_match, first_match);
free(tmp[0]);
free(tmp[1]);
free(tmp);
	return ;
}

void set_start_room(t_lemin *everything)
{
	everything->rooms[everything->r_ct - 1].start = TRUE;
	return ;
}

void set_end_room(t_lemin *everything)
{
	everything->rooms[everything->r_ct - 1].end = FALSE;
	return ;
}
