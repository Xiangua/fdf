/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_rev_list_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 22:23:22 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:24:07 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	aff_rev_list_str(t_list *new)
{
	if (new == NULL)
		return ;
	else
		aff_rev_list_str(new->next);
	ft_putendl(new->content);
}
