/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 17:18:33 by folier            #+#    #+#             */
/*   Updated: 2015/07/18 17:24:33 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_strtab_del(char	***tabdel)
{
	int			i;
	char		**tmp;

	i = 0;
	if (!*tabdel)
		return ;
	tmp = *tabdel;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	*tabdel = NULL;
}
