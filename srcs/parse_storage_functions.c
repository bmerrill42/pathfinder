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

void store_edge (char **line,  t_lemin *everything)
{
	if (!everything->rooms->connections)
		new_str_array(*line, &everything->connections);
	else
		add_to_str_array(*line, &everything->connections);
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
