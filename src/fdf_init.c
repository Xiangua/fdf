/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 23:50:23 by folier            #+#    #+#             */
/*   Updated: 2015/07/15 00:39:03 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_fdf		*fdf_init(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 420, 420, "fdf");
	sleep(5);
	return (fdf);
}
