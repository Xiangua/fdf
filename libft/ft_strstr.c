/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:07:19 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:34:31 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_resostr(const char *s1, const char *s2)
{
	int			i[2];
	char		*tmp;

	i[0] = 0;
	i[1] = 0;
	while (s1[i[0]] != 0)
	{
		while (s1[i[0]] == s2[i[1]])
		{
			i[0]++;
			i[1]++;
			if (s2[i[1]] == 0)
			{
				tmp = (char *)&s1[i[0] - i[1]];
				return (tmp);
			}
		}
		if (i[1] != 0)
		{
			i[0] = i[0] - i[1];
			i[1] = 0;
		}
		i[0]++;
	}
	return (NULL);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	char		*tmp;

	if (*s2 == '\0')
		tmp = (char *)s1;
	else
		tmp = ft_resostr(s1, s2);
	return (tmp);
}
