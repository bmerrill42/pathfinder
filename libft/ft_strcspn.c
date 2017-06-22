/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:40:57 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/15 14:27:14 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s1, const char s2)
{
	const char	*sc1;

	sc1 = s1;
	while (*sc1 != '\0')
	{
		if (*sc1 == s2)
			return (sc1 - s1);
		++sc1;
	}
	return (sc1 - s1);
}
