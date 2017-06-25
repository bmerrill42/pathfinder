#include "../includes/lem_in.h"

void new_str_array(char *str, char ***array)
{
	(*array) = (char **)ft_memalloc(sizeof(char**));
	(*array)[0] = ft_strdup(str);
}

void add_to_str_array(char *str, char ***array)
{
	char **tmp;
	int i;

	i = 0;
	tmp = (char**)ft_memalloc(sizeof(*array) + sizeof(char**));
	while (i < (int)(sizeof(*array) / sizeof(char**)))
	{
		tmp[i] = ft_strdup((*array)[i]);
		i++;
	}
	tmp[i] = ft_strdup(str);
	while (--i > -1)
		free((*array)[i]);
	free((*array));
	(*array) = tmp;
}

void store_room(char **line, t_lemin *everything)
{
	if (!everything->room_names)
		new_str_array(*line, &everything->room_names);
	else
		add_to_str_array(*line, &everything->room_names);
	everything->r_ct++;
}

void store_edge (char **line,  t_lemin *everything)
{
	if (!everything->connections)
		new_str_array(*line, &everything->connections);
	else
		add_to_str_array(*line, &everything->connections);
	return ;
}

void set_start_room(t_lemin *everything)
{
	everything->start = everything->r_ct - 1;
	return ;
}

void set_end_room(t_lemin *everything)
{
	everything->end = everything->r_ct - 1;
	return ;
}
