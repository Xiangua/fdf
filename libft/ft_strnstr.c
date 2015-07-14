/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:06:54 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:33:46 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#define I i[0]
#define Y i[1]

static char	*ft_resonstr(const char *s1, const char *s2, size_t n)
{
	size_t	i[2];
	char	*tmp;

	I = 0;
	Y = 0;
	while (s1[I] != 0 && I < n)
	{
		while (s1[I] == s2[Y] && I < n)
		{
			I++;
			Y++;
			if (s2[Y] == 0)
			{
				tmp = (char *)&s1[I - Y];
				return (tmp);
			}
		}
		if (Y != 0)
		{
			I = I - Y;
			Y = 0;
		}
		I++;
	}
	return (NULL);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*tmp;

	if (n < ft_strlen(s2))
		return (NULL);
	else if (*s2 == '\0')
		tmp = (char *)s1;
	else
		tmp = ft_resonstr(s1, s2, n);
	return (tmp);
}
