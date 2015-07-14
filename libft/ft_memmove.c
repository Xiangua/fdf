/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:30:15 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:28:14 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = s1;
	src = s2;
	i = n - 1;
	if (s2 <= s1)
	{
		while (n > 0)
		{
			dest[i] = src[i];
			i--;
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
