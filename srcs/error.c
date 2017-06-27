/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 01:08:03 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/27 01:08:06 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		throw_error(int error)
{
	if (error == GENERIC)
		write(2, "\x1b[31mERROR\x1b[0m\n", 15);
	else if (error == NO_ANTS)
		write(2, "\x1b[31mERROR\nNO ANTS\x1b[0m\n", 23);
	else if (error == NO_END)
		write(2, "\x1b[31mERROR\nNO END ROOM FOUND\x1b[0m\n", 34);
	else if (error == DUP_END)
		write(2, "\x1b[31mERROR\nMORE THAN ONE END\x1b[0m\n", 34);
	else if (error == NO_START)
		write(2, "\x1b[31mERROR\nNO START FOUND\x1b[0m\n", 36);
	else if (error == DUP_START)
		write(2, "\x1b[31mERROR\nMORE THAN ONE START\x1b[0m\n", 36);
	else if (error == NO_ROOMS)
		write(2, "\x1b[31mERROR\nNO ROOMS\x1b[0m\n", 25);
	else if (error == NO_VALID_PATH)
		write(2, "\x1b[31mERROR\nNO PATH POSSIBLE\x1b[0m\n", 33);
	else if (error == DUP_NAME)
		write(2, "\x1b[31mERROR\nDUPLICATE NAME\x1b[0m\n", 31);
	else if (error == MALLOC_FAIL)
		write(2, "\x1b[31mERROR\nALLOCATION FAILURE\x1b[0m\n", 35);
	else if (error == BAD_ROOM_NAME)
		write(2, "\x1b[31mERROR\nBAD_ROOM_NAME\x1b[0m\n", 29);
	exit(EXIT_FAILURE);
}
