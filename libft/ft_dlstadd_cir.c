/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_cir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 19:02:46 by folier            #+#    #+#             */
/*   Updated: 2015/07/18 21:46:39 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_dlstadd_cir(t_dlist **lstcir, t_dlist *elem)
{
	t_dlist		*tmp;
	t_dlist		*tmp2;

	tmp2 = NULL;
	if (!*lstcir)
	{
		*lstcir = elem;
		return ;
	}
	tmp = *lstcir;
	if (!tmp->next)
	{
		tmp->next = elem;
		tmp->prev = elem;
		elem->next = tmp;
		elem->prev = tmp;
	}
	else {
		tmp->prev = tmp2;
		tmp->prev = elem;
		elem->next = tmp;
		tmp2->next = elem;
		elem->prev = tmp2;
	}
}
