/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 23:10:25 by folier            #+#    #+#             */
/*   Updated: 2015/07/15 20:31:17 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <libft.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_list			*img;
}					t_fdf;

t_fdf				*fdf_init(void);
void				fdf_put(t_fdf *fdf);
void				fdf_parsing(char **, t_fdf *);
void				fdf_error_msg(int);
void				fdf_error_exit(int);

#endif
