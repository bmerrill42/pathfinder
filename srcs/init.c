#include "../includes/lem_in.h"

void	init_rooms(t_room **rooms,t_room **tmp, int i)
{
	tmp[i]->name = ft_strdup((*rooms)[i].name);
	tmp[i]->start = (*rooms)[i].start;
	tmp[i]->end = (*rooms)[i].end;
	tmp[i]->visited = (*rooms)[i].visited;
	tmp[i]->connections = (*rooms)[i].connections;
	tmp[i]->c_count = (*rooms)[i].c_count;
}
