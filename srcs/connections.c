#include "../includes/lem_in.h"

void new_connection_array(t_room *room, int neighbor)
{
	room->connections = (int*)malloc(sizeof(int));
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
