/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 23:01:44 by folier            #+#    #+#             */
/*   Updated: 2015/07/15 00:39:12 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				main(int ac, char **av)
{
	(void)av;
	t_fdf		*fdf;
	if (ac < 2)
	{
		ft_putendl("fdf usage: passez un fichier en parametre");
		return (0);
	}
	fdf = fdf_init();
	return (0);
}
