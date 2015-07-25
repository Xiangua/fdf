/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 23:01:44 by folier            #+#    #+#             */
/*   Updated: 2015/07/25 21:11:47 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				main(int ac, char **av)
{
	t_fdf		*fdf;
	if (ac < 2)
	{
		fdf_error_msg("", "", 2);
		return (0);
	}
	fdf = fdf_init();
	fdf_parsing(av, fdf, ac);
	fdf_lst_to_tab(fdf);
	fdf_put(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
