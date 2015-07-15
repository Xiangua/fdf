/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 07:31:37 by folier            #+#    #+#             */
/*   Updated: 2015/07/15 19:53:16 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fdf.h>
#define I i[0]
#define Y i[1]

void		fdf_put(t_fdf *fdf)
{
	int			i[2] = {0, 0};

	printf("ptr dans put  mlx: %p, win %p\n", fdf->mlx, fdf->win);
	while (I < 40)
	{
		while (Y < 40)
		{
			//printf("value I: %d, Y: %d\n", I, Y);
			mlx_pixel_put(fdf->mlx, fdf->win, 100 + I, 100 +Y, 0xFF0000);
			Y++;
		}
		Y = 0;
		I++;
	}
}
