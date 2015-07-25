/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 23:10:25 by folier            #+#    #+#             */
/*   Updated: 2015/07/25 21:10:40 by folier           ###   ########.fr       */
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

typedef struct		s_elem
{
	int				**tab;
	int				x_max;
	int				y_max;
	char			*name;
	t_list			*t_tab;
}					t_elem;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_dlist			*img;
}					t_fdf;

typedef struct		s_err
{
	char			*str1;
	char			*str2;
	char			*str3;
}					t_err;

t_fdf				*fdf_init(void);
void				fdf_put(t_fdf *fdf);
void				fdf_parsing(char **, t_fdf *, int);
void				fdf_lst_to_tab(t_fdf *);
void				fdf_error_msg(char *,char *, int);
void				fdf_error_exit(int);
void				fdf_msg(int, const char *);
t_dlist				*fdf_create_img(char *);
void				fdf_destroy_img(t_dlist **);

#endif
