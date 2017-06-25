#include "../includes/lem_in.h"

void		throw_error(int ERR)
{
	if (ERR == GENERIC)
		write(2,"\x1b[31mERROR\x1b[0m\n", 15);
	else if (ERR == NO_ANTS)
		write(2,"\x1b[31mERROR\nNO ANTS\x1b[0m\n", 23);
	else if (ERR == NO_END)
		write(2,"\x1b[31mERROR\nNO END ROOM FOUND\x1b[0m\n", 34);
	else if (ERR == DUP_END)
		write(2,"\x1b[31mERROR\nMORE THAN ONE END\x1b[0m\n", 34);
	else if (ERR == NO_START)
		write(2,"\x1b[31mERROR\nNO START FOUND\x1b[0m\n", 36);
	else if (ERR == DUP_START)
		write(2,"\x1b[31mERROR\nMORE THAN ONE START\x1b[0m\n", 36);
	else if (ERR == NO_ROOMS)
		write(2,"\x1b[31mERROR\nNO ROOMS\x1b[0m\n", 25);
	else if (ERR == NO_VALID_PATH)
		write(2,"\x1b[31mERROR\nNO PATH POSSIBLE\x1b[0m\n",33);
	else if (ERR == DUP_NAME)
		write(2,"\x1b[31mERROR\nDUPLICATE NAME\x1b[0m\n", 31);
	else if (ERR == MALLOC_FAIL)
		write(2,"\x1b[31mERROR\nALLOCATION FAILURE\x1b[0m\n", 35);
	else if (ERR == BAD_ROOM_NAME)
		write(2, "\x1b[31mERROR\nBAD_ROOM_NAME\x1b[0m\n", 29);
	exit(EXIT_FAILURE);
}


