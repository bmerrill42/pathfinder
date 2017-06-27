/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:14:08 by tpan              #+#    #+#             */
/*   Updated: 2017/06/26 19:27:17 by tpan             ###   ########.fr       */
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
	tmp = (int*)malloc(((*path).index + 1) * sizeof(int));
	while (i < (*path).index)
	{
		tmp[i] = (*path).pathfinder[i];
		i++;
	}
	tmp[i] = index;
	free((*path).pathfinder);
	(*path).pathfinder = tmp;
}

void		add_path(t_path *path, int index)
{
	if (path->pathfinder == NULL)
		new_int_array(path, index);
	else
		add_int_to_array(path, index);
	path->index++;
}

int			remove_path(t_path *path)
{
	int *tmp;
	int i;

	i = 0;
	tmp = (int*)malloc(((*path).index + 1) * sizeof(int));
	while (i < (*path).index)
	{
		tmp[i] = (*path).pathfinder[i];
		i++;
	}
	free((*path).pathfinder);
	(*path).pathfinder = tmp;
	path->index--;
	return (0);
}

int			find_path(t_room **rooms, t_path *path, int index)
{
	int conn_i;

	if (!(*rooms))
		return (0);
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
		return (remove_path(path));
	while (conn_i < (*rooms)[index].c_count &&
			!find_path(rooms, path, (*rooms)[index].connections[conn_i]))
		conn_i++;
	if (conn_i == (*rooms)[index].c_count)
		return (remove_path(path));
	return (1);
}
