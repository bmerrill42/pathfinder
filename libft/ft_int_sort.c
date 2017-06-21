/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:44:15 by tpan              #+#    #+#             */
/*   Updated: 2017/05/31 19:35:09 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_int_sort takes an array of ints and returns a new array with the ints
** sorted from smallest to largest.
*/

static int		get_smallest_unused_int(int *arr, int *used, int len)
{
	int		i;
	int		smallest;
	int		sm_index;
	int		set;

	i = 0;
	set = 0;
	while (i < len)
	{
		if ((arr[i] < smallest || !set) && !used[i])
		{
			smallest = arr[i];
			sm_index = i;
			set = 1;
		}
		i++;
	}
	used[sm_index] = 1;
	return (smallest);
}

static int		all_used(int *used, int len)
{
	int		i;

	i = 0;
	while (i < len)
		if (used[i++] == 0)
			return (0);
	return (1);
}

int				*ft_int_sort(int *arr, int len)
{
	int		i;
	int		*sorted;
	int		*used;

	sorted = (int *)malloc(sizeof(int) * len);
	used = (int *)malloc(sizeof(int) * len);
	ft_bzero(sorted, sizeof(int) * len);
	ft_bzero(used, sizeof(int) * len);
	i = 0;
	while (!all_used(used, len))
		sorted[i++] = get_smallest_unused_int(arr, used, len);
	free(used);
	return (sorted);
}
