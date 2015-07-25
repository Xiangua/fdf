/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 20:08:23 by folier            #+#    #+#             */
/*   Updated: 2015/07/25 21:09:27 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		fdf_error_msg(char *msg, char *msg2, int op)
{
	t_err		err[] = {
		{"fdf: open fail \"", "\"  - ", " - "},
		{"fdf: fichier \"", "\" invalide, ligne [", "] illegal caractere"},
		{"fdf: usage - veuillez passer des fichiers bien formate en argument -", "", ""}
	};

	ft_putstr(err[op].str1);
	ft_putstr(msg);
	ft_putstr(err[op].str2);
	ft_putstr(msg2);
	ft_putendl(err[op].str3);
}

void		fdf_error_exit(int op)
{
	(void)op;
	exit(-1);
}
