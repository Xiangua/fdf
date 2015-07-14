# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: folier <folier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/14 22:51:05 by folier            #+#    #+#              #
#    Updated: 2015/07/15 00:38:44 by folier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -Wall -Werror -Wextra -g
INCLUDE = -I ./inc -I libft/includes
LIB = -L/usr/X11/lib -lmlx -lXext -lX11
CC = clang
PTH_SRC = src
PTH_OBJ = obj
PTH_INC = inc
PTH_LFT = libft
LFT = $(PTH_LFT)/libft.a
SRC = main.c
OBJ = $(patsubst %.c, $(PTH_OBJ)/%.o, $(SRC))

all: $(LFT) $(NAME)

$(LFT):
	@make -C libft

$(NAME): $(OBJ)
	@$(CC) $(FLAG) $(OBJ) $(LFT) $(LIB) -o $@
	@echo " compilation de fdf fini"	


$(PTH_OBJ)/%.o: $(addprefix $(PTH_SRC)/, %.c)
	@mkdir -p $(PTH_OBJ)
	@echo -n .
	@$(CC) $(FLAG) -o $@ -c $< $(INCLUDE)

clean:
	@make -C libft clean
	@rm -rf $(PTH_OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
