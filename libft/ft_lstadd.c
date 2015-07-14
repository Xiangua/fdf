/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:27:53 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:25:51 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!*alst && !new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}
