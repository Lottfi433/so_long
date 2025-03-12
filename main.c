/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazlaigi <yazlaigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:05 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/02/03 12:18:51 by yazlaigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd, char *mapname)
{
	int		i;
	char	**hold;
	int		lines;

	lines = count_lines(mapname);
	hold = malloc (lines * sizeof(char *));
	if (hold == NULL)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		hold[i] = get_next_line(fd);
		if (hold[i] == NULL)
		{
			memmory_free(hold, i);
			return (NULL);
		}
		i++;
	}
	return (hold);
}

void	load_map_images(t_game *game)
{
	game->img_bg = mlx_xpm_file_to_image(game->mlx, "textures/background.xpm",
			&game->width, &game->height);
	if (!game->img_bg)
		exit (0);
	game->mlx_win = mlx_new_window(game->mlx, game->map_w * TILE_SIZE,
			game->map_h * TILE_SIZE, "So_Long");
	if (!game->mlx_win)
		exit (0);
	game->walls_img = mlx_xpm_file_to_image(game->mlx, "textures/wallimg.xpm",
			&game->width, &game->height);
	if (!game->walls_img)
		exit (0);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&game->width, &game->height);
	if (!game->collect_img)
		exit (0);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->width, &game->height);
	if (!game->player_img)
		exit (0);
	game->door_img = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm",
			&game->width, &game->height);
	if (!game->door_img)
		exit (0);
	game->moves = 0;
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->copy[i] != NULL)
	{
		j = 0;
		while (game->copy[i][j] != '\0')
		{
			render_tile(game, i, j);
			j++;
		}
		i++;
	}
}

void	render_tile(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = TILE_SIZE * j;
	y = TILE_SIZE * i;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game ->img_bg, x, y);
	if (game->copy[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->walls_img, x, y);
	if (game->copy[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player_img, x, y);
	if (game->copy[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->collect_img, x, y);
	if (game->copy[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->door_img, x, y);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2)
	{
		game = malloc (sizeof(t_game));
		if (!game)
			exit(0);
		game->mapname = av[1];
		main_helper2(game);
		main_helper(game);
		if (parsing(game->hold, game->mapname) == 0)
			exit(0);
		get_player_position(game);
		load_map_images(game);
		render_map(game);
		mlx_hook(game->mlx_win, 2, 1L << 0, handle_keyboard, game);
		mlx_hook(game->mlx_win, 17, 0, handle_close, game);
		mlx_loop(game->mlx);
		memmory_free(game->copy, count_lines(game->mapname));
		memmory_free(game->hold, count_lines(game->mapname));
		free(game);
	}
	write(2, "Wrong number of args !", 22);
}
