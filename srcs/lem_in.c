#include "../includes/lem_in.h"

void burn_them_all(t_lemin *lemin)
{
	int i;

	i = 0;
	while ()
}

int	main(void)
{
	t_lemin lemin;

	parse_input(&lemin);
	if (!find_path(&lemin.rooms, &lemin.path, lemin.start))
		throw_error(GENERIC);
	print_ants(&lemin);
	burn_them_all(&lemin)
}
