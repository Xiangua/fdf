/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 19:58:12 by folier            #+#    #+#             */
/*   Updated: 2015/07/23 10:45:40 by folier           ###   ########.fr       */
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
	printf("av: [%s]\n", av);
	tmp = ft_strsplit_ac(av, ' ', &ac);
	while (i < ac)
	{
		if (!(is_string_isalpha(tmp[i++])))
			return (0);
	}
	store_in_fdf(fdf, tmp);
	//ft_strtab_del(&tmp);
	return (1);
}

static int			read_arg(int fd, t_fdf *fdf)
{
	int			ret;
	char		*line;
	int			cnt;
	int			err;

	ret = 1;
	cnt = 1;
	line = NULL;
	err = 1;
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
		{
			ft_putendl("errer gnl");
			err = 0;
		}
		if (!(split_line(fdf, line)))
		{
			ft_putendl("errer split_line");
			err = 0;
		}
	}
	return (err);
}


void display_list(t_dlist *list) {
	t_dlist *tmp;
	tmp = list;
	int i = 0;

	ft_putendl("debut display liste");
	while (i < 10) {
		printf("Element %d. Nom : %s\n", i, ((t_elem *)(tmp->content))->name);
		//printf("nom: %s\n", ((t_elem *)(tmp->content)));
		i++;
		tmp = tmp->next;
	}
}

void				fdf_parsing(char **av, t_fdf *fdf, int ac)
{
	int			i;
	int			fd;
	int			test;
	t_dlist		*tmp;

	i = 1;
	while (i < ac)
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
				printf("Fichier %d KO!\n", i);
			}
			else
			{
				printf("Fichier %d OK!\n", i);
				fdf_msg(1, av[i]);
			}
			printf("close fd: %d\n", fd);
			test = close(fd);
			ft_putnbr(test);
			ft_putendl("");

		}
		i++;
		if (i > 4)
			display_list(fdf->img);
	}
}
