# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: folier <folier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/14 22:51:05 by folier            #+#    #+#              #
#    Updated: 2015/07/18 22:59:32 by folier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -Wall -Werror -Wextra -g
INCLUDE = -I ./inc -I libft/includes -I /minilibx_macos
LIB = -framework OpenGL -framework AppKit
CC = clang
PTH_SRC = src
PTH_OBJ = obj
PTH_INC = inc
PTH_LFT = libft
PTH_MLX = minilibx_macos
MLX = $(PTH_MLX)/libmlx.a
LFT = $(PTH_LFT)/libft.a
SRC = main.c fdf_init.c fdf_put.c fdf_parsing.c fdf_error.c fdf_mgr_img.c \

OBJ = $(patsubst %.c, $(PTH_OBJ)/%.o, $(SRC))

all: $(LFT) $(MLX) $(NAME)

$(LFT):
	@make -C $(PTH_LFT)

$(MLX):
	@make -C $(PTH_MLX)

$(NAME): $(OBJ)
	@$(CC) $(FLAG) $(OBJ) $(LFT) $(MLX) $(LIB) -o $@
	@echo " compilation de fdf fini"	


$(PTH_OBJ)/%.o: $(addprefix $(PTH_SRC)/, %.c)
	@mkdir -p $(PTH_OBJ)
	@echo -n .
	@$(CC) $(FLAG) -o $@ -c $< $(INCLUDE)

clean:
	@make -C $(PTH_LFT) clean
	@make -C $(PTH_MLX) clean
	@rm -rf $(PTH_OBJ)

fclean: clean
	@make -C $(PTH_LFT) fclean
	@make -C $(PTH_MLX) clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
