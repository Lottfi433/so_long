# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 11:08:57 by yasserlotfi       #+#    #+#              #
#    Updated: 2025/01/03 16:28:25 by yasserlotfi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c
OBJ = $(SRC:.c=.o)
MLX_DIR = /Users/yasserlotfi/studies/cursus/so_long/minilibx_opengl_20191021
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
