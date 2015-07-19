/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 19:58:12 by folier            #+#    #+#             */
/*   Updated: 2015/07/18 21:38:09 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void			store_in_fdf(t_fdf *fdf, char **tab)
{
	(void)fdf;
	(void)tab;
}	

static int			is_string_isalpha(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i++])))
			return (0);
	}
	return (1);
}

static int			split_line(t_fdf *fdf, const char *av)
{
	char			**tmp;
	int				ac;
	int				i;

	i = 0;
	tmp = ft_strsplit_ac(av, ' ', &ac);
	while (i < ac)
	{
		if (!(is_string_isalpha(tmp[i])))
			return (0);
	}
	store_in_fdf(fdf, tmp);
	ft_strtab_del(&tmp);
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
	t_dlist		*tmp;

	i = 1;
	while (av[i])
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			fdf_error_msg(3);
		else
		{
			tmp = fdf_create_img(av[i], fdf);
			if (!(read_arg(fd, fdf)))
			{
				fdf_error_msg(4);
				fdf_destroy_img(fdf, tmp);
			}
		}
		i++;
	}
}
