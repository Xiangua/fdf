/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 23:29:58 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:26:02 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_lstadd_last(t_list **list, t_list *elem)
{
	t_list		*tmp;

	tmp = *list;
	if (!*list && !elem)
		return ;
	if (!*list)
	{
		*list = elem;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}
