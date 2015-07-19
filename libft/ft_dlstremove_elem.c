/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 23:05:23 by folier            #+#    #+#             */
/*   Updated: 2015/07/19 02:29:05 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	remove_frist_elem(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*tmp;

	tmp = *dlst;
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
	while (tmp && (tmp != *dlst))
	{
		if (tmp == elem)
		{
			tmp2 = tmp->next;
			tmp2->prev = tmp->prev;
			tmp->prev->next = tmp2;
			ft_dlstdel_one(&tmp, del);
			return ;
		}
		tmp = tmp->next;
	}

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
		remove_frist_elem(dlst, del);
}
