/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 17:18:33 by folier            #+#    #+#             */
/*   Updated: 2015/07/21 21:42:00 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

void			ft_strtab_del(char	***tabdel)
{
	int			i;
	char		**tmp;

	i = 0;
	if (!*tabdel)
		return ;
	tmp = *tabdel;
	ft_putendl("free ?");
	while (tmp[i])
	{
		printf("tmp[%d]: %s\n", i, tmp[i]);
		free(tmp[i++]);
	}
	ft_putendl("free whilend");
	free(tmp);
	*tabdel = NULL;
	ft_putendl("free end");
}
