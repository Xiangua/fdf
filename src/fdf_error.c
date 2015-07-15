/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 20:08:23 by folier            #+#    #+#             */
/*   Updated: 2015/07/15 20:30:35 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		fdf_error_msg(int op)
{
	(void)op;
	ft_putstr("fdf: erreur - ");
	ft_putstr(strerror(errno));
	ft_putendl(" -");
}

void		fdf_error_exit(int op)
{
	(void)op;
	exit(-1);
}
