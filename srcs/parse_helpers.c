/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 01:01:29 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/27 16:34:07 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_command(char *line)
{
	int i;

	i = 2;
	if (line[0] == '\0')
		return (0);
	while (line[0] == '#' && line[1] == '#' && ft_isprint(line[i]))
		i++;
	if (line[i] != '\0')
		return (0);
	ft_putendl(line);
	return (1);
}

int		is_start(char **line, t_lemin *everything)
{
	if (ft_strcmp(*line, "##start"))
		return (0);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		throw_error(BAD_ROOM_NAME);
	set_start_room(everything);
	return (1);
}

int		is_end(char **line, t_lemin *everything)
{
	if (ft_strcmp(*line, "##end"))
		return (0);
	ft_putendl(*line);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		throw_error(BAD_ROOM_NAME);
	set_end_room(everything);
	return (1);
}

int		extra_command(char **line, t_lemin *everything)
{
	if (!ft_strcmp(*line, "##end") || !ft_strcmp(*line, "##start"))
		return (0);
	if (!is_command(*line))
		return (0);
	free(*line);
	get_next_line(0, line);
	if (!is_room(line, everything))
		throw_error(BAD_ROOM_NAME);
	return (1);
}

void	dup_roomp(char **line, t_lemin *everything)
{
	int		i;
	int		space;
	char	*tmp;

	space = 0;
	while ((*line)[space] != ' ')
		space++;
	tmp = ft_strsub(*line, 0, space);
	i = 0;
	while (i < (*everything).r_ct)
	{
		if (!ft_strcmp(tmp, (*everything).rooms[i].name))
		{
			free(tmp);
			throw_error(DUP_NAME);
		}
		i++;
	}
	free(tmp);
}
