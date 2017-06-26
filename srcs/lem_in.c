#include "../includes/lem_in.h"

int main()
{
	t_lemin lemin;

	parse_input(&lemin);
	if (!find_path(&lemin.rooms, &lemin.path, lemin.start))
		throw_error(GENERIC);
	print_ants(&lemin);
}
