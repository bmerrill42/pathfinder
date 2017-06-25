/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 20:14:08 by tpan              #+#    #+#             */
/*   Updated: 2017/06/24 23:51:30 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		find_path(t_room *rooms, t_path *path, int index)
{
	int i;

	if (!rooms)
		return 0;
	i = 0;
	rooms[index]->visited = TRUE;
	while (rooms[rooms[index]->connections[i]]->visited == TRUE && i < c_count)
		i++;
	if (i == c_count)
		return (0);
	add_path(path, index);
	if (room[index]->end)
		return 1;
	while (!find_path(rooms, path, rooms[index]->connections[i]) && i < c_count)
		i++;
	if (i == c_count)
	{
		remove_path(path, index);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_lemin everything;
	
	everything.rooms = (t_room*)malloc(sizeof(t_room) * 4);
	everything.rooms[0].name = "start";
	everything.rooms[0].start = TRUE;
	everything.rooms[0].visited = FALSE;
	everything.rooms[0].index = 0;
	everything.rooms[0].connections = (int*)malloc(sizeof(int) * 2);
	everything.rooms[0].connections[0] = 1;
        everything.rooms[0].connections[1] = 3;
	everything.rooms[1].name = "butts";
	everything.rooms[1].start = FALSE;
	everything.rooms[1].visited = FALSE;
	everything.rooms[1].index = 1;
	everything.rooms[1].connections = (int*)malloc(sizeof(int) * 2);
	everything.rooms[1].connections[0] = 0;
        everything.rooms[1].connections[1] = 3;
	everything.rooms[2].name = "end";
	everything.rooms[2].start = FALSE;
	everything.rooms[2].visited = TRUE;
	everything.rooms[2].index = 2;
	everything.rooms[2].connections = (int*)malloc(sizeof(int));
	everything.rooms[2].connections[0] = 3;
	everything.rooms[3].name = "extra";
	everything.rooms[3].start = FALSE;
	everything.rooms[3].visited = FALSE;
	everything.rooms[3].index = 3;
	everything.rooms[3].connections = (int*)malloc(sizeof(int) * 3);
	everything.rooms[3].connections[0] = 0;
        everything.rooms[3].connections[1] = 1;
        everything.rooms[3].connections[2] = 2;
	everything.start= 0;
	everything.end= 2;
	everything.r_ct = 4;
	everything.ant_count = 10;
	if (!find_path(everything.rooms, &everything.path, everything.start))
		throw_error(GENERIC);
//	print_ants(everything);
	return 0;
}
