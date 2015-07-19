/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:28:05 by folier            #+#    #+#             */
/*   Updated: 2015/07/18 21:25:06 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL)
	{
		if ((*alst)->next != NULL)
			ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
	}
}
