#include "../includes/lem_in.h"

void		malloc_rooms(t_lemin *everything)
{
	everything->rooms = (t_room *)malloc(sizeof(t_room) * (everything->r_ct));
	ft_bzero(everything->rooms, sizeof(everything->rooms));
}

void		init_rooms(t_lemin *everything)
{
	everything.rooms[i].name = room_names;

}
