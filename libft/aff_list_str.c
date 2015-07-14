/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_list_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:22:52 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:23:55 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	aff_list_str(t_list *new)
{
	if (new == NULL)
		return ;
	else
	{
		ft_putendl(new->content);
		aff_list_str(new->next);
	}
}
