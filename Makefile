# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 10:10:33 by aalcara-          #+#    #+#              #
#    Updated: 2021/06/23 16:43:39 by aalcara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	cub3d_init.c \
		cub3d_parsing.c \
		cub3d_utils.c \
		cub3d_utils2.c \
		cub3d.c \
		errors.c \
		exit.c \
		get_next_line_utils.c \
		get_next_line.c \
		map_parsing.c \
		map_utils.c \
		move_keys.c \
		raycasting_init.c \
		raycasting_move.c \
		raycasting_utils.c \
		raycasting.c \
		save_check.c \
		save.c \
		sprite_init.c \
		sprite.c \
		texture_draw.c \
		texture_get.c \
		texture_init.c

NAME = cub3D

MLX_DIR = lib/minilibx-linux
MLX = libmlx.a
CC = clang

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = -lmlx -lm -lbsd -lX11 -lXext

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

# declaring OBJ with the same name of SRC files, with .o extention in place of .c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) $(MLXFLAGS)
		@echo $(NAME) : Created!

#% symbol replace every name that has at least one character
# in this case the ends with .o or .c;
# $< referes to the first prerequisite, in this case :$(SRC_DIR)/%.c;
# $@ refers to the self namo of rule, in this case $(OBJ_DIR)/%.o.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@

# -C flag chages to MLX_DIR to start a new make;
$(MLX):
	@echo ------------------
	@echo making minilibx
	@make --no-print-directory -C $(MLX_DIR)
	@echo done minilibx!
	@echo ------------------

clean:
	@rm -fr $(OBJ_DIR)
	@echo "obj deleted"

fclean: clean
	@rm -fr $(NAME)
	@echo "[$(NAME)]: deleted"

re: fclean all

.PHONY: all, clean, fclean, re
