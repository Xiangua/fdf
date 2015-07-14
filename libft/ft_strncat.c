/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:06:23 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:32:46 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		cnt;

	i = ft_strlen(s1);
	cnt = 0;
	while (s2[cnt] != '\0' && n > 0)
	{
		s1[i] = s2[cnt];
		i++;
		cnt++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
