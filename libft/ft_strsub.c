/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:07:25 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:34:41 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(sizeof(char*) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (len > 0)
	{
		new[i] = s[start];
		start++;
		i++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
