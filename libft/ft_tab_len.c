/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:30:57 by tpan              #+#    #+#             */
/*   Updated: 2017/05/22 19:33:07 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the number of entries in a char ** table
*/

int			ft_tab_len(char **table)
{
	int		i;

	i = 0;
	while (table && table[i])
		i++;
	return (i);
}
