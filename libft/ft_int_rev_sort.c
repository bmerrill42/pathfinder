/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_rev_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:44:15 by tpan              #+#    #+#             */
/*   Updated: 2017/05/31 19:32:15 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_int_rev_sort takes an array of ints and returns a new array with the ints
** sorted from largest to smallest.
*/

static int		get_largest_unused_int(int *arr, int *used, int len)
{
	int		i;
	int		largest;
	int		lg_index;
	int		set;

	i = 0;
	set = 0;
	while (i < len)
	{
		if ((arr[i] > largest || !set) && !used[i])
		{
			largest = arr[i];
			lg_index = i;
			set = 1;
		}
		i++;
	}
	used[lg_index] = 1;
	return (largest);
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

int				*ft_int_rev_sort(int *arr, int len)
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
		sorted[i++] = get_largest_unused_int(arr, used, len);
	free(used);
	return (sorted);
}
