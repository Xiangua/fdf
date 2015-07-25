/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lst_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 18:42:02 by folier            #+#    #+#             */
/*   Updated: 2015/07/25 20:08:09 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define ELEM ((t_elem *)(img->content))

void			fdf_lst_to_tab(t_fdf *fdf)
{
	t_dlist		*img;
	int			out;

	img = fdf->img;
	out = 1;
	while (out)
	{
		if (fdf->img->prev == img)
			out = 0;
		printf("nom: %s, x: %d, y: %d\n", ELEM->name, ELEM->x_max, ELEM->y_max);
		img = img->next;
	}
}
