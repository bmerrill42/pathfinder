/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:06:17 by tpan              #+#    #+#             */
/*   Updated: 2017/05/31 19:33:31 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Look for a delimiter.
*/

static int	ft_is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/*
** Count the number of tokens by parsing the string.
*/

static int	ft_tokencount(char *str, char *delim)
{
	int		i;
	int		flag;
	int		count;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_is_delim(str[i], delim))
		{
			count += flag;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	count += flag;
	return (count);
}

static int	ft_tokenlen(char *str, char *delim)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && !ft_is_delim(str[i], delim))
		i++;
	return (i);
}

char		**ft_strtok(char *str, char *delim)
{
	int		i;
	int		k;
	int		tok_len;
	char	**tok;

	if (!str || !(tok =
			(char **)malloc(sizeof(char *) * (ft_tokencount(str, delim) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (k < ft_tokencount(str, delim))
	{
		while (ft_is_delim(str[i], delim))
			i++;
		tok_len = ft_tokenlen(&str[i], delim);
		if (!(tok[k] = (char *)malloc(sizeof(char) * (tok_len + 1))))
			return (NULL);
		ft_strncpy(tok[k], &str[i], tok_len);
		tok[k][tok_len] = '\0';
		while (str[i] && !ft_is_delim(str[i], delim))
			i++;
		k++;
	}
	tok[k] = NULL;
	return (tok);
}
