/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:06:47 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:33:38 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest)
	{
		ft_bzero(dest, (size + 1));
		return (dest);
	}
	return (NULL);
}
