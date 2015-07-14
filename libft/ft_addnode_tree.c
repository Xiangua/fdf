/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnode_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 10:34:41 by folier            #+#    #+#             */
/*   Updated: 2015/06/18 22:09:02 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_addnode_tree(t_tree **tree, t_tree **parent, t_tree *nod, int (*func)(void *, void *))
{
	if (*tree)
	{
		if (func((*tree)->content, nod->content) > 0)
			ft_addnode_tree(&(*tree)->right, &(*tree), nod, func);
		else
			ft_addnode_tree(&(*tree)->left, &(*tree), nod, func);
	}
	else
	{
		*tree = nod;
		nod->parent = *parent;
	}
}
