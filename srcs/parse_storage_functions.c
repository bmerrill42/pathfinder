#include "../includes/lem_in.h"

void new_str_array(char *str, t_room **rooms)
{
	int i;

	i = 0;
	(*rooms) = (t_room *)ft_memalloc(sizeof(t_room));
	while (str[i] != ' ')
		i++;
	(*rooms)[0].name = ft_strsub(str, 0, i);
	rooms[0]->start = FALSE;
	rooms[0]->end = FALSE;
	rooms[0]->visited = FALSE;
	rooms[0]->connections = NULL;
	rooms[0]->c_count = 0;
}

void add_to_str_array(char *str, t_room **rooms, int num_rooms)
{
	t_room *tmp;
	int i;
	int stri;

	i = 0;
	tmp = (t_room *)ft_memalloc((num_rooms + 1) * sizeof(t_room));
	while (i < num_rooms)
	{
		tmp[i].name = ft_strdup((*rooms)[i].name);
		tmp[i].start = (*rooms)[i].start;
		tmp[i].end = (*rooms)[i].end;
		tmp[i].visited = (*rooms)[i].visited;
		tmp[i].connections = (*rooms)[i].connections;
		tmp[i].c_count = (*rooms)[i].c_count;
		i++;
	}
	tmp[i].start = FALSE;
	tmp[i].end = FALSE;
	tmp[i].visited = FALSE;
	tmp[i].connections = NULL;
	stri = 0;
	while (str[stri] != ' ')
		stri++;
	tmp[i].name = ft_strsub(str, 0, stri);
	tmp[i].c_count = 0;
	stri = 0;
	while (stri < num_rooms)
	{
		free((*rooms)[stri].name);
		stri++;
	}
	free(*rooms);
	(*rooms) = tmp;
}

void store_room(char **line, t_lemin *everything)
{
	if (!(*everything).rooms)
		new_str_array(*line, &everything->rooms);
	else
		add_to_str_array(*line, &everything->rooms, everything->r_ct);
	everything->r_ct++;
}

void new_connection_array(t_room *room, int neighbor)
{
	int *tmp;
	tmp = (int*)malloc(sizeof(int));
	room->connections = tmp;
	free(tmp);
	room->connections[0] = neighbor;
}

void add_connection_array(t_room *room, int neighbor)
{
	int *tmp;
	int i;

	i = 0;
	tmp = (int*)malloc((room->c_count + 1) * sizeof(int));
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
		new_connection_array(&everything->rooms[room], neighbor);
	else
		add_connection_array(&everything->rooms[room], neighbor);
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
	while (i < everything->r_ct && ft_strcmp(everything->rooms[i].name, tmp[0]))
		i++;
	first_match = i;
	i = 0;
	while (i < everything->r_ct && ft_strcmp(everything->rooms[i].name, tmp[1]))
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
	everything->start = everything->r_ct - 1;
	everything->rooms[everything->r_ct - 1].start = TRUE;
	return ;
}

void set_end_room(t_lemin *everything)
{
	everything->end = everything->r_ct - 1;
	everything->rooms[everything->r_ct - 1].end = TRUE;
	return ;
}
