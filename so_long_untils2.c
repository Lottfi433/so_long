/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_untils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazlaigi <yazlaigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:29:59 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/02/03 12:18:00 by yazlaigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*move;

	game->moves++;
	move = ft_itoa(game->moves);
	write(1, "the number of moves :", 21);
	write(1, move, ft_strlen(move));
	write(1, "\n", 1);
	free(move);
}

int	last_map_checking(char **hold, char *mapname)
{
	int	i;
	int	j;

	i = 0;
	if (map_checker(mapname) == 1)
	{
		while (i < count_lines(mapname))
		{
			j = 0;
			while (hold[i][j] != '\0')
			{
				if ((hold[i][j] != '1' && hold [i][j] != '*'
					&& hold[i][j] != '0') || hold[i][j] == '\n')
					return (0);
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	get_player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->copy[x] != NULL)
	{
		y = 0;
		while (game->copy[x][y] != '\0')
		{
			if (game->copy[x][y] == 'P')
			{
				game->player_x = y;
				game->player_y = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_y < 0 || new_y >= game->map_h || new_x >= game->map_w)
		return ;
	if (game->copy[new_y][new_x] == '1' || (game->copy[new_y][new_x] == 'E'
		&& starting_ending_colect_checker(game->copy, game->mapname) == 1))
		return ;
	else if (game->copy[new_y][new_x] == 'C')
		game->copy[new_y][new_x] = '0';
	else if (game->copy[new_y][new_x] == 'E'
		&& starting_ending_colect_checker(game->copy, game->mapname) == 0)
	{
		print_moves(game);
		write(1, "Game is finished !\n", 19);
		exit (0);
	}
	game->copy[game->player_y][game->player_x] = '0';
	game->copy[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	print_moves(game);
	render_map(game);
}

int	handle_keyboard(int key_code, t_game *game)
{
	if (key_code == 53)
		exit (0);
	else if (key_code == 13)
		move_player(game, 0, -1);
	else if (key_code == 0)
		move_player(game, -1, 0);
	else if (key_code == 1)
		move_player(game, 0, 1);
	else if (key_code == 2)
		move_player(game, 1, 0);
	return (0);
}
