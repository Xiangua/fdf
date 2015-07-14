/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 10:56:02 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:26:53 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list			*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list		*new_lst;
	t_list		*tmp_new_lst;
	t_list		*back_f;
	t_list		*tmp_lst;

	if (!list && !f)
		return (NULL);
	back_f = f(list);
	new_lst = ft_lstnew(back_f->content, back_f->content_size);
	tmp_new_lst = new_lst;
	tmp_lst = list;
	while (tmp_lst->next)
	{
		tmp_lst = tmp_lst->next;
		back_f = f(tmp_lst);
		tmp_new_lst->next = ft_lstnew(back_f->content, back_f->content_size);
		tmp_new_lst = tmp_new_lst->next;
	}
	return (new_lst);
}
