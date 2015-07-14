/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:05:55 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:32:21 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#define SIZE tab[0]
#define LEN tab[1]

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*src2;
	size_t		tab[2];
	char		*dst2;

	LEN = size;
	dst2 = dst;
	src2 = src;
	SIZE = size;
	while (*dst2 != '\0' && SIZE-- != 0)
		dst2++;
	LEN = dst2 - dst;
	SIZE = size - LEN;
	if (SIZE == 0)
		return (LEN + ft_strlen(src2));
	while (*src2 != '\0')
	{
		if (SIZE != 1)
		{
			*dst2++ = *src2;
			SIZE--;
		}
		src2++;
	}
	*dst2 = '\0';
	return (LEN + (src2 - src));
}
