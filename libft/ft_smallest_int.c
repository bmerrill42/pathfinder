/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:15:39 by tpan              #+#    #+#             */
/*   Updated: 2017/05/25 11:23:30 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the index of the smallest int in an array.
*/

int		ft_smallest_int(int *arr, int size)
{
	int		smallest;
	int		sm_index;
	int		i;

	smallest = arr[0];
	sm_index = 0;
	i = 1;
	while (i < size)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			sm_index = i;
		}
		i++;
	}
	return (sm_index);
}
