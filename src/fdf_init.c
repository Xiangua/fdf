/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 23:50:23 by folier            #+#    #+#             */
/*   Updated: 2015/07/15 08:25:08 by folier           ###   ########.fr       */
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
	mlx_pixel_put(fdf->mlx, fdf->win, 210, 210, 0xFF0000);
	mlx_pixel_put(fdf->mlx, fdf->win, 210, 211, 0xFF0000);
	mlx_pixel_put(fdf->mlx, fdf->win, 211, 210, 0xFF0000);
	mlx_pixel_put(fdf->mlx, fdf->win, 211, 211, 0xFF0000);
	return (fdf);
}
