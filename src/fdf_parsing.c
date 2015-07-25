/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 19:58:12 by folier            #+#    #+#             */
/*   Updated: 2015/07/25 20:58:19 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define ERR tab[0]
#define I tab[1]


static void			store_in_fdf(t_elem *elem, char **tab, int ac)
{
	int				i;
	int				*tab_i;

	i = 0;
	if (!(tab_i = (int *)malloc(sizeof(int) * ac)))
		return ;

	while (i < ac)
	{
		tab_i[i] = ft_atoi(tab[i]);
		i++;
	}
	ft_lstadd(&(elem->t_tab), ft_lstnew(tab_i, sizeof(int) * ac));
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

static int			split_line(t_elem *elem, const char *av)
{
	char			**tmp;
	int				ac;
	int				i;

	i = 0;
	tmp = ft_strsplit_ac(av, ' ', &ac);
	if (elem->x_max < ac)
		elem->x_max = ac;
	elem->y_max++;
	while (i < ac)
	{
		if (!(is_string_isalpha(tmp[i++])))
			return (0);
	}
	store_in_fdf(elem, tmp, ac);
	//ft_strtab_del(&tmp);
	return (1);
}

static int			read_arg(int fd, t_elem *elem, int *cnt)
{
	int			ret;
	char		*line;
	int			err;

	ret = 1;
	line = NULL;
	err = 1;
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
		{
			err = 0;
		}
		if (!(split_line(elem, line)))
		{
			err = 0;
		}
		*cnt = *cnt + 1;
	}
	return (err);
}

void				fdf_parsing(char **av, t_fdf *fdf, int ac)
{
	int			tab[2] = {1, 1};
	int			fd;
	t_dlist		*tmp;

	while (I < ac)
	{
		if ((fd = open(av[I], O_RDONLY)) == -1)
			fdf_error_msg(av[I], strerror(errno), 0);
		else
		{
			tmp = fdf_create_img(av[I]);
			if (!(read_arg(fd, tmp->content, &ERR)))
			{
				fdf_error_msg(av[I], ft_itoa(ERR), 1);
				fdf_destroy_img(&tmp);
			}
			else
			{
				fdf_msg(1, av[I]);
				ft_dlstadd_cir(&(fdf->img), tmp);
			}
			close(fd);
		}
		I++;
		ERR = 1;
	}
}
