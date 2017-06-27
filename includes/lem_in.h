/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 20:18:06 by tpan              #+#    #+#             */
/*   Updated: 2017/06/27 01:07:27 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"
# include <stdbool.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define BOLD		"\x1b[1m"
# define UL			"\x1b[4m"
# define RESET		"\x1b[0m"
# define ECOLE42	GREEN P1
# define P1			"        :::      ::::::::\n       :+:      :+:    :+:\n" P2
# define P2			"    +:+ +:+         +:+  \n  +#+  +:+       +#+     \n" P3
# define P3			"+#+#+#+#+#+   +#+        \n     #+#    #+#          \n" P4
# define P4			"    ###   ########.us.org    \n"

enum				e_err
{
	GENERIC,
	NO_ANTS,
	NO_END,
	DUP_END,
	NO_START,
	DUP_START,
	NO_ROOMS,
	NO_VALID_PATH,
	DUP_NAME,
	MALLOC_FAIL,
	BAD_ROOM_NAME
};

typedef struct		s_path
{
	int		*pathfinder;
	int		index;
}					t_path;

typedef struct		s_room
{
	bool	start;
	bool	end;
	char	*name;
	bool	visited;
	int		*connections;
	int		c_count;
}					t_room;

typedef struct		s_lemin
{
	int		start;
	int		end;
	int		ant_count;
	int		r_ct;
	t_room	*rooms;
	t_path	path;
}					t_lemin;

int					is_command(char *line);
int					is_start(char **line, t_lemin *everything);
int					is_end(char **line, t_lemin *everything);
int					extra_command(char **line, t_lemin *everything);
void				dup_roomp(char **line, t_lemin *everything);
void				print_ants(t_lemin *everything);
void				throw_error(int error);
void				store_room(char **line, t_lemin *everything);
void				store_edge (char **line, t_lemin *everything);
void				set_start_room(t_lemin *everything);
void				set_end_room(t_lemin *everything);
int					is_edge_list (char **line, t_lemin *everything);
int					is_roomlist (char **line, t_lemin *everything);
int					is_ant(char **line, t_lemin *everything);
int					is_command(char *line);
int					is_comment(char **line);
int					is_room(char **line, t_lemin *everything);
int					is_start(char **line, t_lemin *everything);
int					is_end(char **line, t_lemin *everything);
int					extra_command(char **line, t_lemin *everything);
int					is_edge(char **line, t_lemin *everything);
int					parse_input(t_lemin *everything);
int					find_path(t_room **rooms, t_path *path, int index);
void				add_connection(t_lemin *everything, int room, int neighbor);
void				init_rooms(t_room **rooms,t_room **tmp, int i);
#endif
