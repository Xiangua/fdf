/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 10:26:11 by folier            #+#    #+#             */
/*   Updated: 2015/06/19 10:16:24 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void 	ft_map_tree(t_tree *tree, void (*func)(void *))
{
	if (!tree)
		return ;
	if (tree->left)
		ft_map_tree(tree->left, func);
	func(tree->content);
	if (tree->right)
		ft_map_tree(tree->right, func);
}
