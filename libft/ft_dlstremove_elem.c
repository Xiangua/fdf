/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 23:05:23 by folier            #+#    #+#             */
/*   Updated: 2015/07/22 10:42:25 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static void	remove_first_elem(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*tmp;

	tmp = *dlst;
	ft_putendl("deux");
	if (tmp->prev)
	{
		tmp->prev->next = (*dlst)->next;
		(*dlst)->next->prev = tmp->prev;
		*dlst = tmp->next;
	}
	else
	{
		*dlst = tmp->next;
		(*dlst)->prev = NULL;
	}
	ft_dlstdel_one(&tmp, del);
}

static void	remove_elem(t_dlist **dlst, t_dlist *elem, void (*del)(void *))
{
	t_dlist	*tmp;
	t_dlist *tmp2;

	tmp2 = NULL;
	tmp = (*dlst)->next;
	ft_putendl("remove elem pre boucle");
	while (tmp && (tmp != *dlst))
	{
		if (tmp == elem)
		{
			tmp2 = tmp->next;
			tmp2->prev = tmp->prev;
			tmp->prev->next = tmp2;
			if (tmp2 == tmp2->next)
			{
				ft_putendl("test");
				tmp2->next = NULL;
				tmp2->prev = NULL;
			}
			ft_dlstdel_one(&elem, del);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putendl("remove elem post boucle");
}

void		ft_dlstremove_elem(t_dlist **dlst, t_dlist *elem, void (*del)(void *))
{
	t_dlist	*tmp;

	tmp = *dlst;
	if (tmp && !tmp->next && (tmp == elem))
	{
		ft_dlstdel_one(&tmp, del);
		*dlst = NULL;
	}
	else if (tmp && tmp->next && (tmp != elem))
		remove_elem(dlst, elem, del);
	else
		remove_first_elem(dlst, del);
}
