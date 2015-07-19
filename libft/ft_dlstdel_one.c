/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 21:15:56 by folier            #+#    #+#             */
/*   Updated: 2015/07/18 21:47:47 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_dlstdel_one(t_dlist **dlst, void (*del)(void *))
{
	if (*dlst)
	{
		del((*dlst)->content);
		(*dlst)->next = NULL;
		(*dlst)->prev = NULL;
		free(*dlst);
		*dlst = NULL;
	}
}
