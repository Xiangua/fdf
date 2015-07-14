/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:29:08 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:27:29 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dest;
	char			*src;
	unsigned char	chr;
	int				i;

	i = 0;
	dest = (char *)s1;
	src = (char *)s2;
	chr = (unsigned char)c;
	while (n)
	{
		if ((unsigned char)(dest[i] = src[i]) == chr)
			return (dest + (++i));
		n--;
		i++;
	}
	return (NULL);
}
