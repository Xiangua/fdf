/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:31:31 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:29:50 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*tmp;
	int		i;

	tmp = (char *)s;
	i = 0;
	while (tmp[i] != '\0')
	{
		ft_putchar_fd(tmp[i], fd);
		i++;
	}
}
