/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_storage_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 01:08:57 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/27 14:48:46 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	new_str_array(char *str, t_room **rooms)
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

void	old_rooms_free(t_room **rooms, int num_rooms)
{
	int stri;

	stri = 0;
	while (stri < num_rooms)
	{
		free((*rooms)[stri].name);
		stri++;
	}
}

void	add_to_str_array(char *str, t_room **rooms, int num_rooms)
{
	t_room	*tmp;
	int		i;
	int		stri;

	i = 0;
	tmp = (t_room *)malloc((num_rooms + 1) * sizeof(t_room));
	while (i < num_rooms)
	{
		init_rooms(rooms, &tmp, i);
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
	old_rooms_free(rooms, num_rooms);
	free(*rooms);
	(*rooms) = tmp;
}

void	store_room(char **line, t_lemin *everything)
{
	if (!(*everything).rooms)
		new_str_array(*line, &everything->rooms);
	else
	{
		dup_roomp(line, everything);
		add_to_str_array(*line, &everything->rooms, everything->r_ct);
	}
	everything->r_ct++;
}

void	store_edge(char **line, t_lemin *everything)
{
	char	**tmp;
	int		i;
	int		first_match;
	int		second_match;

	i = 0;
	tmp = ft_strsplit(*line, '-');
	while (i < everything->r_ct && ft_strcmp(everything->rooms[i].name, tmp[0]))
		i++;
	first_match = i;
	i = 0;
	while (i < everything->r_ct && ft_strcmp(everything->rooms[i].name, tmp[1]))
		i++;
	if (i >= everything->r_ct)
		throw_error(GENERIC);
	second_match = i;
	add_connection(everything, first_match, second_match);
	add_connection(everything, second_match, first_match);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	return ;
}
