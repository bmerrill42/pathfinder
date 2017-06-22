/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 20:18:06 by tpan              #+#    #+#             */
/*   Updated: 2017/06/21 17:36:25 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

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

typedef enum		e_error
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
	MALLOC_FAIL
}					t_error;

#endif
