/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:05 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/19 14:58:44 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd, char *mapname)
{
	int		i;
	char	**hold;

	hold = malloc (count_lines(mapname) * sizeof(char *));
	if (hold == NULL)
		return (0);
	i = 0;
	while (i < count_lines(mapname))
	{
		hold[i] = get_next_line(fd);
		if (hold[i] == NULL)
			memmory_free(hold);
		i++;
	}
	return (hold);
}

void	load_map_images(t_game *game)
{
	game->img_bg = mlx_xpm_file_to_image(game->mlx, "background.xpm",
			&game->width, &game->height);
	game->mlx_win = mlx_new_window(game->mlx, game->map_w * TILE_SIZE,
			game->map_h * TILE_SIZE, "Hello world!");
	game->walls_img = mlx_xpm_file_to_image(game->mlx, "wallimg.xpm",
			&game->width, &game->height);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "collect.xpm",
			&game->width, &game->height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "player.xpm",
			&game->width, &game->height);
	game->door_img = mlx_xpm_file_to_image(game->mlx, "door.xpm",
			&game->width, &game->height);
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
		game->mapname = av[1];
		game->hold = map_two_d(game->hold, game->mapname);
		game->copy = map_two_d(game->hold, game->mapname);
		game->map_w = ft_strlen(game->hold[0]);
		game->map_h = count_lines(game->mapname);
		if (parsing(game->hold, game->mapname) == 0)
		{
			write(1, "Fix your map", 12);
			exit(0);
		}
		game->mlx = mlx_init();
		get_player_position(game);
		load_map_images(game);
		render_map(game);
		mlx_hook(game->mlx_win, 2, 1L << 0, handle_keyboard, game);
		mlx_loop(game->mlx);
		memmory_free(game->copy);
		memmory_free(game->hold);
	}
	write(1, "Wrong number of args !", 22);
}
