# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: folier <folier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/12 00:09:44 by folier            #+#    #+#              #
#    Updated: 2015/07/18 23:06:54 by folier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_putchar.c ft_putendl.c ft_putnbr.c ft_putstr.c ft_strcpy.c \
	 ft_strdup.c ft_strlen.c ft_strncpy.c ft_strnew.c \
	 ft_strcmp.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	 ft_memset.c ft_memcpy.c ft_memccpy.c ft_isdigit.c ft_isascii.c \
	 ft_isprint.c ft_strncmp.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	 ft_toupper.c ft_tolower.c ft_memmove.c ft_strchr.c ft_strrchr.c \
	 ft_strstr.c ft_strnstr.c ft_memchr.c ft_memcmp.c ft_putchar_fd.c \
	 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memalloc.c \
	 ft_strequ.c ft_strnequ.c ft_strclr.c ft_strsub.c ft_strjoin.c \
	 ft_memdel.c ft_strdel.c ft_strtrim.c ft_striter.c ft_striteri.c \
	 ft_strmap.c ft_strmapi.c ft_itoa.c ft_strsplit.c ft_lstnew.c \
	 ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstadd.c aff_list_str.c \
	 aff_rev_list_str.c lst_ascii.c get_next_line.c ft_lstmap.c \
	 ft_lstclone_elem.c ft_lstclone_list.c ft_lstadd_last.c ft_lstview.c \
	 ft_create_node_tree.c ft_map_tree.c ft_addnode_tree.c ft_clear_tree.c \
	 ft_intlength.c ft_strsplit_ac.c ft_strtab_del.c ft_create_dlst.c \
	 ft_dlstadd_cir.c ft_dlstadd_last.c ft_dlstadd.c ft_dlstiter.c \
	 ft_dlstdel.c ft_dlstdel_one.c ft_dlstremove_elem.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@echo -n .
	@cc -I. -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib libft.a
	@echo "libft ok"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
