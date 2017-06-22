#include "includes/lem_in.h"

void		throw_error(int ERR)
{
	if (ERR == GENERIC)
		write(2,"\e[31mERROR\n", 12);
	else if (ERR == NO_ANTS)
		write(2,"\e31mERROR\nNO ANTS\n", 20);
	else if (ERR == NO_END)
		write(2,"\e31mERROR\nNO END ROOM FOUND\n", 30);
	else if (ERR == DUP_END)
		write(2,"\e31mERROR\nMORE THAN ONE END\n", 30);
	else if (ERR == NO_START)
		write(2,"\e31mERROR\nNO START FOUND\n", 32);
	else if (ERR == DUP_START)
		write(2,"\e31mERROR\nMORE THAN ONE START\n", 32);
	else if (ERR == NO_ROOMS)
		write(2,"\e31mERROR\nNO ROOMS\n", 21);
	else if (ERR == NO_VALID_PATH)
		write(2,"\e31mERROR\nNO PATH POSSIBLE\n",29);
	else if (ERR == DUP_NAME)
		write(2,"\e31mERROR\nDUPLICATE NAME\n", 27);
	else if (ERR == MALLOC_FAIL)
		write(2,"\e31mERROR\nALLOCATION FAILURE\n", 31);
	exit(EXIT_FAILURE);
}


