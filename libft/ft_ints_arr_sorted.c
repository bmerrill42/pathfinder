/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints_arr_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:28:22 by tpan              #+#    #+#             */
/*   Updated: 2017/05/25 11:29:51 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns 1 if the array is sorted from smallest to largest, 0 otherwise.
*/

int		ft_ints_arr_sorted(int *ints, int len)
{
	int i;

	if (len == 1)
		return (1);
	i = 1;
	while (i < len)
	{
		if (ints[i - 1] >= ints[i])
			return (0);
		i++;
	}
	return (1);
}
