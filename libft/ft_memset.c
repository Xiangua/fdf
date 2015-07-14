/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:30:24 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:28:25 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = b;
	while (b &&len > 0)
	{
		tmp[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (tmp);
}
