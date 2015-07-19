/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 10:52:50 by folier            #+#    #+#             */
/*   Updated: 2015/07/19 10:56:04 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			fdf_msg(int op, const char *txt)
{
	ft_putstr("fdf: le fichier ");
	ft_putstr(txt);
	ft_putstr("est accepte");
	(void)op;
}
