# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yazlaigi <yazlaigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 11:08:57 by yasserlotfi       #+#    #+#              #
#    Updated: 2025/02/03 11:11:02 by yazlaigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line_utils.c get_next_line.c so_long_untils2.c so_long_utils.c walls.c ft_itoa.c
OBJ = $(SRC:.c=.o)
MLX_DIR = /Users/yazlaigi/Desktop/minilibx_opengl_20191021
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
