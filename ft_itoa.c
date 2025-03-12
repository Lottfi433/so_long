/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazlaigi <yazlaigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:47:57 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/02/03 11:47:42 by yazlaigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	numberlen(int number)
{
	size_t	count;

	if (number <= 0)
		count = 1;
	else
		count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	number;
	size_t	num_len;
	char	*a;

	number = n;
	num_len = numberlen(number);
	a = malloc (num_len + 1);
	if (a == NULL)
		return (NULL);
	a[num_len] = '\0';
	if (number < 0)
	{
		a[0] = '-';
		number = number * -1;
	}
	if (number == 0)
		a[0] = '0';
	while (number != 0)
	{
		a[--num_len] = (number % 10) + '0';
		number = number / 10;
	}
	return (a);
}

void	main_helper2(t_game *game)
{
	game->hold = map_two_d(game->hold, game->mapname);
	if (game->hold == NULL)
	{
		write(2, "Error to allocate", 17);
		exit (0);
	}
	game->copy = map_two_d(game->hold, game->mapname);
	if (game->copy == NULL)
	{
		memmory_free(game->hold, count_lines(game->mapname));
		write(2, "Error to allocate", 17);
		exit (0);
	}
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		memmory_free (game->hold, count_lines(game->mapname));
		memmory_free (game->copy, count_lines(game->mapname));
		write(1, "Error !", 7);
		exit(0);
	}
}

void	main_helper(t_game *game)
{
	game->map_w = ft_strlen(game->hold[0]);
	game->map_h = count_lines(game->mapname);
	if (ft_strlen(game->mapname) <= 4
		|| game->mapname[ft_strlen(game->mapname) - 1] != 'r'
		|| game->mapname[ft_strlen(game->mapname) - 2] != 'e'
		|| game->mapname[ft_strlen(game->mapname) - 3] != 'b'
		|| game->mapname[ft_strlen(game->mapname) - 4] != '.'
		|| game->mapname[ft_strlen(game->mapname) - 5] == '/')
	{
		write(2, "Fix Map Name!", 13);
		exit(0);
	}
}
