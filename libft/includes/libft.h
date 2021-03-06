/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folier <folier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 00:09:11 by folier            #+#    #+#             */
/*   Updated: 2015/07/23 10:28:14 by folier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/uio.h>
# include <sys/types.h>
# define BUFF_SIZE 34

typedef struct		s_gnl 
{
	char			*rest;
	size_t			size_rest;
	int				line;
	int				read_ret;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_tree
{
	void			*content;
	char			color;
	struct s_tree	*parent;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
char				*ft_strnew(size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memmove(void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
int					ft_strequ(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_ac(char const *s, char c, int *);
int					get_next_line(const int fd, char **line);
void				ft_strtab_del(char ***);
int					ft_intlength(long long int n);

/************/
/*	T_LIST	*/
/************/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_last(t_list **list, t_list *elem);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				aff_list_str(t_list *new);
t_list				*inser_tri(char *s1, t_list *first);
void				aff_rev_list_str(t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstclone_list(const t_list *list);
t_list				*ft_lstclone_elem(const t_list *elem);
void				ft_lstview(t_list *list);

/************/
/*	T_DLIST	*/
/************/

t_dlist				*ft_create_dlst(void *);
void				ft_dlstadd_cir(t_dlist **, t_dlist *);
void				ft_dlstadd_last(t_dlist **, t_dlist *);
void				ft_dlstadd(t_dlist **, t_dlist *);
void				ft_dlstiter(t_dlist *, void (*f)(void *));
void				ft_dlstdel(t_dlist **, void (*f)(void *));
void				ft_dlstdel_one(t_dlist **, void (*f)(void *));
void				ft_dlstremove_elem(t_dlist **, t_dlist *, void (*f)(void *));

/************/
/*	T_TREE	*/
/************/

t_tree		*ft_create_node_tree(void *);
void		ft_map_tree(t_tree *, void (*func)(void *));
void		ft_addnode_tree(t_tree **, t_tree **, t_tree *, int (*func) (void *, void *));
void		ft_clear_tree(t_tree **, void (*free_content)(void *));



#endif /*	END LIBFT_H	*/
