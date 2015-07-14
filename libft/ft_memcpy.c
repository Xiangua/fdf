/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:29:44 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:27:54 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	int			i;
	char		*s1b;
	const char	*s2b;

	i = 0;
	s1b = s1;
	s2b = s2;
	while (n > 0)
	{
		s1b[i] = s2b[i];
		n--;
		i++;
	}
	return (s1b);
}
