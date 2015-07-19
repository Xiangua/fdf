/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:50:21 by folier            #+#    #+#             */
/*   Updated: 2015/07/18 21:40:47 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_dlist			*ft_create_dlst(void *elem)
{
	t_dlist		*dlist;

	if (!(dlist = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	dlist->next = NULL;
	dlist->prev = NULL;
	dlist->content = elem;
	return (dlist);
}
