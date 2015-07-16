/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 19:58:12 by folier            #+#    #+#             */
/*   Updated: 2015/07/16 11:10:48 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int			split_line(t_fdf *fdf, const char *av)
{
	char			**tmp;
	int				ac;

	(void)fdf;
	tmp = ft_strsplit_ac(av, ' ', &ac);

	printf("nombre d'element par ligne: %d\n", ac);
	return (1);
}

static int			read_arg(int fd, t_fdf *fdf)
{
	int			ret;
	char		*line;
	int			cnt;

	ret = 1;
	cnt = 1;
	line = NULL;
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (0);
		if (!(split_line(fdf, line)))
			return (0);
	}
	return (1);
}

void				fdf_parsing(char **av, t_fdf *fdf)
{
	int			i;
	int			fd;

	i = 1;
	while (av[i])
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			fdf_error_msg(3);
		else
		{
			if (!(read_arg(fd, fdf)))
				fdf_error_msg(4);
		}
		i++;
	}
}
