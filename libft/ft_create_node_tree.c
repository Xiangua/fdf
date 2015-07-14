/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 10:11:19 by folier            #+#    #+#             */
/*   Updated: 2015/05/21 11:41:04 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_tree	*ft_create_node_tree(void *data)
{
	t_tree	*node;

	node = NULL;
	if(!(node = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	node->parent = NULL;
	node->color = 'r';
	node->left = NULL;
	node->right = NULL;
	node->content = data;
	return (node);
}
