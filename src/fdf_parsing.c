/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 19:58:12 by folier            #+#    #+#             */
/*   Updated: 2015/07/15 20:31:36 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				fdf_parsing(char **av, t_fdf *fdf)
{
	int			i;
	int			fd;

	i = 1;
	(void)fdf;
	while (av[i])
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			fdf_error_msg(3);
		i++;
	}
}
