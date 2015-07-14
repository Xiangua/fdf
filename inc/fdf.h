/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 23:10:25 by folier            #+#    #+#             */
/*   Updated: 2015/07/15 00:36:55 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <libft.h>
#include <mlx.h>

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
}					t_fdf;


t_fdf				*fdf_init(void);

#endif
