/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazlaigi <yazlaigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:03:01 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/02/03 12:12:58 by yazlaigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif
# ifndef TILE_SIZE
#  define TILE_SIZE 40
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_game
{
	char	**hold;
	char	**copy;
	void	*mlx;
	void	*mlx_win;
	void	*img_bg;
	void	*walls_img;
	void	*door_img;
	void	*player_img;
	void	*collect_img;
	int		map_h;
	int		map_w;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		moves;
	char	*mapname;
}	t_game;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_strchr(char *str);
int		ft_strlen(char *str);
char	*after_newline(char *str);
char	*before_newline(char *str);
int		count_chars(char *filename);
int		count_lines(char *filename);
char	**map_two_d(char **hold, char *mapname);
void	memmory_free(char **hold, int x);
int		starting_ending_colect_checker(char **hold, char *mapname);
int		player_position_i(char **hold, char *mapname, char c);
int		player_position_j(char **hold, char *mapname, char c);
char	**flood(char **hold, int i, int j);
int		last_map_checking(char **hold, char *mapname);
int		map_checker(char *mapname);
int		parsing(char **hold, char *mapname);
size_t	numberlen(int number);
char	*ft_itoa(int n);
void	render_tile(t_game *game, int i, int j);
void	render_map(t_game *game);
void	load_map_images(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		handle_keyboard(int key_code, t_game *game);
void	get_player_position(t_game *game);
char	**read_map(int fd, char *mapname);
int		handle_close(t_game *game);
void	main_helper(t_game *game);
void	main_helper2(t_game *game);
void	print_moves(t_game *game);
#endif
