/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:18:50 by folier            #+#    #+#             */
/*   Updated: 2015/05/19 09:35:19 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		end_of_file(char **line, char *inter, char *save_line)
{
	if (*line && *inter)
	{
		*line = ft_strdup(inter);
		if (save_line)
			ft_bzero(save_line, sizeof(save_line));
		return (1);
	}
	return (0);
}

static int		ft_strlen_len(char *inter)
{
	int		i;

	i = 0;
	while (inter[i] != '\n' && inter[i] != '\0')
		i++;
	return (i);
}

void			malloc_line(char **line, char *inter)
{
	(*line) = ft_strnew(ft_strlen_len(inter));
	(*line) = ft_strncpy((*line), inter, ft_strlen_len(inter));
}

int				get_next_line(int const fd, char **line)
{
	char				*buff;
	int					i;
	char				*inter;
	static char			*save_line;
	int					save;

	inter = ((save_line) ? ft_strdup(save_line) : ft_strnew(BUFF_SIZE));
	while (inter && (!ft_strchr(inter, '\n')))
	{
		if ((buff = ft_strnew(BUFF_SIZE)))
		{
			if ((save = read(fd, buff, BUFF_SIZE)) > 0)
				inter = ft_strjoin(inter, buff);
			else if (save == 0)
				return (end_of_file(line, inter, save_line));
			else
				return (-1);
			free(buff);
		}
	}
	malloc_line(line, inter);
	i = ft_strlen_len(inter);
	save_line = ft_strsub(inter, i + 1, (ft_strlen(inter) - i));
	free(inter);
	return (1);
}
