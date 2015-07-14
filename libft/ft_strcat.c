/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:32:49 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:30:03 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		cnt;

	i = ft_strlen(s1);
	cnt = 0;
	while (s2[cnt] != '\0')
	{
		s1[i] = s2[cnt];
		i++;
		cnt++;
	}
	s1[i] = '\0';
	return (s1);
}
