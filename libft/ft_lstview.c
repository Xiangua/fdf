/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstview.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 23:54:01 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:27:12 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstview(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		write(1, (char *)tmp->content, tmp->content_size);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}
