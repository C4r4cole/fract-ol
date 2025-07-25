# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:07:46 by fmoulin           #+#    #+#              #
#    Updated: 2025/07/24 11:50:29 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME	= fractol

# Fichiers sources
SRCS	= main.c my_mlx_pxl.c init.c render.c mapping.c complex_operations.c

# Répertoires
SRC_DIR	= src
OBJ_DIR = obj
INC_DIR = include

# Objets
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR) -Ilibft -Imlx
RM = rm -f

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# MiniLibX
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd

# Règle par défaut
all: $(LIBFT) $(MLX_LIB) $(NAME)

# Compilation de Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compilation de MiniLibX
$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

# Compilation de ton projet
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LIBFT) $(MLX_FLAGS)

# Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Nettoyage
clean:
	$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
