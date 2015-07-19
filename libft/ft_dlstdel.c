/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 20:54:53 by folier            #+#    #+#             */
/*   Updated: 2015/07/18 21:47:29 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_dlstdel(t_dlist **dlst, void (*del) (void *))
{
	if (*dlst != NULL)
	{
		if ((*dlst)->prev)
			(*dlst)->prev->next = NULL;
		if ((*dlst)->next != NULL)
			ft_dlstdel(&((*dlst)->next), del);
		ft_dlstdel_one(dlst, del);
	}
}
