/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:02:08 by tpan              #+#    #+#             */
/*   Updated: 2017/05/24 13:08:49 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Erase and free a table/paragraph of strings (char ***), set the ptr to null.
*/

void		ft_tab_del(char ***table)
{
	int		i;

	i = 0;
	if (table && *table)
	{
		while ((*table)[i])
			ft_strdel(&(*table)[i++]);
		free(*table);
		*table = NULL;
	}
	return ;
}
