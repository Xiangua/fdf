/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:07:31 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:34:55 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	int		new;
	char	*dest;

	i = 0;
	end = ft_strlen(s);
	new = 0;
	dest = (char *)malloc(sizeof(char*) * (ft_strlen(s) + 1));
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[end] == '\0' || s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	while (i <= end)
	{
		dest[new] = s[i];
		new++;
		i++;
	}
	dest[new] = '\0';
	return (dest);
}
