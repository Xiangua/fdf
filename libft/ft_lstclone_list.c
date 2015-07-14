/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclone_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 22:24:53 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:26:19 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstclone_list(const t_list *list)
{
	t_list		*new_lst;
	t_list		*tmp1;
	t_list		*tmp2;

	tmp1 = (t_list *)list;
	new_lst = ft_lstclone_elem(tmp1);
	tmp2 = new_lst;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
		tmp2->next = ft_lstclone_elem(tmp1);
		tmp2 = tmp2->next;
	}
	return (new_lst);
}
