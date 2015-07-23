/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 06:42:39 by folier            #+#    #+#             */
/*   Updated: 2015/07/23 10:39:52 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static t_gnl		*manage_static_struct(t_gnl **rec, const int fd)
{
	t_gnl	*rest;

	rest = *rec;
	while (rest)
	{
		rest->line = 0;
		if (rest->fd == fd)
			return (rest);
		rest = rest->next;
	}
	if (!(rest = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	rest->fd = fd;
	rest->rest = ft_strnew(BUFF_SIZE);
	rest->size_rest = 0;
	rest->read_ret = -2;
	rest->line = 0;
	rest->next = *rec;
	*rec = rest;
	return (rest);
}

static void			search_backline(char **line, t_gnl *rec, int read_ret)
{
	int				index;
	int				tmp;

	index = 0;
	tmp = 0;
	rec->read_ret = read_ret;
	while (*line && (*line)[index])
	{
		if ((*line)[index] == '\n')
		{
			(*line)[index] = '\0';
			ft_bzero(rec->rest, BUFF_SIZE);
			if (index < BUFF_SIZE)
				index++;
			while ((*line)[index])
				(rec->rest)[tmp++] = (*line)[index++];
			rec->size_rest = tmp;
			rec->line = 1;
			return ;
		}
		index++;
	}
	rec->size_rest = 0;
}

static int			read_gnl(t_gnl *rest, const int fd, char **line)
{
	char			*buff;
	char			*tmp;
	int				read_ret;

	buff = ft_strnew(BUFF_SIZE + 1);
	if ((read_ret = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	search_backline(&buff, rest, read_ret);
	if (!*line)
		*line = ft_strdup(buff);
	else
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
	return (read_ret);
}

static int			check_end_gnl(t_gnl *rest)
{
	char			*buff;
	int				ret;
	int				fd;

	fd = rest->fd;
	if (rest->size_rest == 0 && fd != 0 && fd != 1 && fd != 2)
	{
		buff = ft_strnew(BUFF_SIZE + 1);
		ft_bzero(rest->rest, BUFF_SIZE + 1);
		if ((ret = read(rest->fd, buff, BUFF_SIZE)) == 0)
			return (1);
		else
		{
			ft_strcpy(rest->rest, buff);
			rest->size_rest = ft_strlen(buff);
			rest->read_ret = ret;
		}
		free(buff);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*rec = NULL;
	t_gnl			*rest;
	char			*buff;
	int				read_ret;

	if (line)
		*line = NULL;
	rest = manage_static_struct(&rec, fd);
	read_ret = rest->read_ret;
	buff = ft_strdup(rest->rest);
	search_backline(&buff, rest, read_ret);
	if (buff && line)
		*line = buff;
	while (line && (read_ret > 0 || read_ret == -2) && rest->line == 0)
		read_ret = read_gnl(rest, fd, line);
	if (read_ret == -1 || !line)
		return (-1);
	if (check_end_gnl(rest))
		return (0);
	return (1);
}
