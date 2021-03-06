/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:07:13 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:34:22 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#define I i[0]
#define Y i[1]
#define SIZE_TAB i[2]
#define INDEX i[3]
#include <stdio.h>

static int		cnt_word(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int		cnt_split(char const *s, char c)
{
	int			i[2];

	I = 0;
	Y = 0;
	while (s[I] == c)
		I++;
	while (s[I] != '\0')
	{
		if (s[I] == c)
		{
			while (s[I] == c)
				I++;
			Y++;
		}
		I++;
	}
	return (Y);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tmp;
	int			i[4];

	I = 0;
	Y = 0;
	INDEX = 0;
	SIZE_TAB = cnt_split(s, c);
	if ((tmp = (char **)malloc(sizeof(char *) * (SIZE_TAB + 1))) == NULL)
		return (NULL);
	while (s[I] != '\0')
	{
		while (s[I] == c)
			I++;
		if (s[I] != '\0')
		{
			tmp[Y] = ft_strnew(cnt_word(s + I, c));
			while (s[I] != c && s[I] != '\0')
				tmp[Y][INDEX++] = s[I++];
			tmp[Y++][INDEX] = '\0';
		}
		INDEX = 0;
	}
	tmp[Y] = NULL;
	return (tmp);
}
