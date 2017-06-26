/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 20:14:08 by tpan              #+#    #+#             */
/*   Updated: 2017/06/25 19:38:52 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		new_int_array(t_path *path, int index)
{
	path->pathfinder = (int*)malloc(sizeof(int) * (path->index + 1));
	path->pathfinder[0] = index;
}

void		add_int_to_array(t_path *path, int index)
{
	int *tmp;
	int i;

	i = 0;
	tmp = (int*)malloc(sizeof(path->index) * sizeof(int));
	while (i < path->index)
	  {
	    tmp[i] = path->pathfinder[i];
	    i++;
	  }
	tmp[i] = index;
	free(path->pathfinder);
	path->pathfinder = tmp;
}

void		add_path(t_path *path, int index)
{
	if (path->pathfinder == NULL)
		new_int_array(path, index);
	else
		add_int_to_array(path, index);
	path->index++;
}

void		remove_path(t_path *path)
{
	path->pathfinder[path->index] = -1;
	path->index--;
}

int		find_path(t_room **rooms, t_path *path, int index)
{
	int conn_i;

	if (!(*rooms))
		return 0;
	if ((*rooms)[index].visited)
	  return (0);
	conn_i = 0;
	(*rooms)[index].visited = TRUE;
	while (conn_i < (*rooms)[index].c_count && 
			(*rooms)[(*rooms)[index].connections[conn_i]].visited == TRUE)
		conn_i++;
	add_path(path, index);
	if ((*rooms)[index].end)
	  return (1);
	if (conn_i == (*rooms)[index].c_count)
		return (0);
	while (conn_i < (*rooms)[index].c_count && 
			!find_path(rooms, path, (*rooms)[index].connections[conn_i]))
		conn_i++;
	if (conn_i == (*rooms)[index].c_count)
	{
		remove_path(path);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_lemin everything;
	
	everything.rooms = (t_room*)malloc(sizeof(t_room) * 4);
	ft_bzero(everything.rooms, sizeof(everything.rooms));
	everything.rooms[0].name = "start";
	everything.rooms[0].start = TRUE;
	everything.rooms[0].end = FALSE;
	everything.rooms[0].visited = FALSE;
	everything.rooms[0].index = 0;
	everything.rooms[0].connections = (int*)malloc(sizeof(int) * 2);
	everything.rooms[0].connections[0] = 1;
    everything.rooms[0].connections[1] = 3;
	everything.rooms[0].c_count = 2;
	everything.rooms[1].name = "butts";
	everything.rooms[1].start = FALSE;
	everything.rooms[1].end = FALSE;
	everything.rooms[1].visited = FALSE;
	everything.rooms[1].index = 1;
	everything.rooms[1].connections = (int*)malloc(sizeof(int) * 2);
	everything.rooms[1].connections[0] = 0;
    everything.rooms[1].connections[1] = 3;
	everything.rooms[1].c_count = 2;
	everything.rooms[2].name = "end";
	everything.rooms[2].start = FALSE;
	everything.rooms[2].end = TRUE;
	everything.rooms[2].visited = FALSE;
	everything.rooms[2].index = 2;
	everything.rooms[2].connections = (int*)malloc(sizeof(int));
	everything.rooms[2].connections[0] = 3;
	everything.rooms[2].c_count = 1;
	everything.rooms[3].name = "extra";
	everything.rooms[3].start = FALSE;
	everything.rooms[3].end = FALSE;
	everything.rooms[3].visited = FALSE;
	everything.rooms[3].index = 3;
	everything.rooms[3].connections = (int*)malloc(sizeof(int) * 3);
	everything.rooms[3].connections[0] = 0;
    everything.rooms[3].connections[1] = 1;
    everything.rooms[3].connections[2] = 2;
	everything.rooms[3].c_count = 3;
	everything.start= 0;
	everything.end= 2;
	everything.r_ct = 4;
	everything.ant_count = 10;
	if (!find_path(&everything.rooms, &everything.path, everything.start))
		throw_error(GENERIC);
//	print_ants(everything);
	return 0;
}
