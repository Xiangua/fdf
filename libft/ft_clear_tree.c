/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 11:57:36 by folier            #+#    #+#             */
/*   Updated: 2015/05/23 09:33:22 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_clear_tree(t_tree **tree, void (*free_content)(void *))
{
	if (!*tree)
		return ;
	if ((*tree)->left != NULL)
		ft_clear_tree(&(*tree)->left, free_content);
	if ((*tree)->right != NULL)
		ft_clear_tree(&(*tree)->right, free_content);
	free_content((*tree)->content);
	free(*tree);
	*tree = NULL;
}
