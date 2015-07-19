/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mgr_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:46:59 by folier            #+#    #+#             */
/*   Updated: 2015/07/19 10:35:29 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_dlist			*fdf_create_img(char *name, t_fdf *fdf)
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
	ft_dlstadd_cir(&(fdf->img), dlst);
	return (dlst);
}

static void		destroy_tab(void *tab, size_t size_tab)
{
	(void)size_tab;
	free((int *)tab);
}

static void		destroy_elem(void *elem)
{
	t_elem		*tmp;

	tmp = (t_elem *)elem;
	free(((t_elem *)elem)->name);
	ft_lstdel(&(tmp->t_tab), destroy_tab);
}

void			fdf_destroy_img(t_fdf *fdf, t_dlist *elem)
{
	ft_dlstremove_elem(&(fdf->img), elem, destroy_elem);
}
