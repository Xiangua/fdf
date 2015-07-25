/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mgr_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:46:59 by folier            #+#    #+#             */
/*   Updated: 2015/07/25 20:55:30 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_dlist			*fdf_create_img(char *name)
{
	t_elem		*elem;
	t_dlist		*dlst;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	elem->name = ft_strdup(name);
	elem->tab = NULL;
	elem->t_tab = NULL;
	elem->y_max = 0;
	elem->x_max = 0;
	dlst = ft_create_dlst(elem);
	return (dlst);
}
/*
static void		destroy_tab(void *tab, size_t size_tab)
{
	(void)size_tab;
	(void)tab;
}*/

void			fdf_destroy_img(t_dlist **img)
{
	t_elem		*elem;

	elem = (t_elem *)((*img)->content);
	//free(elem->name);
//	ft_lstdel(&(elem->t_tab), destroy_tab);
	if (elem->tab)
		free(elem->tab);
	(*img)->next = NULL;
	(*img)->prev = NULL;
	//free(*img);
	*img = NULL;
}
