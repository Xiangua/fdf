/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:05:46 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:32:05 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cnt;
	int		cnt2;
	int		cnttempo;
	char	*new;

	cnt = ft_strlen(s1);
	cnt2 = 0;
	cnttempo = ft_strlen(s2);
	new = (char*)malloc(sizeof(char*) * (cnt + cnttempo + 1));
	if (new == NULL)
		return (NULL);
	while (s1[cnt2] != '\0')
	{
		new[cnt2] = s1[cnt2];
		cnt2++;
	}
	cnt = 0;
	while (s2[cnt] != '\0')
	{
		new[cnt2] = s2[cnt];
		cnt2++;
		cnt++;
	}
	new[cnt2] = '\0';
	return (new);
}
