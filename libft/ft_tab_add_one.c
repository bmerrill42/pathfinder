/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_add_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:44:02 by tpan              #+#    #+#             */
/*   Updated: 2017/05/22 17:57:42 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tab_add_one(char **src_tab, char *new_item)
{
	int		table_len;
	char	**new_table;

	table_len = 0;
	while (src_tab && src_tab[table_len])
		table_len++;
	new_table = (char **)malloc(sizeof(char *) * (table_len + 2));
	ft_bzero(new_table, sizeof(char *) * (table_len + 2));
	ft_memcpy(new_table, src_tab, sizeof(char *) * table_len);
	new_table[table_len] = ft_strdup(new_item);
	new_table[++table_len] = NULL;
	return (new_table);
}
