/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazlaigi <yazlaigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:08:54 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/02/03 12:27:07 by yazlaigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_two_d(char **hold, char *mapname)
{
	int	i;
	int	fd;

	fd = open (mapname, O_RDWR);
	if (fd < 0)
	{
		write(2, "Map not found!", 14);
		exit(0);
	}
	hold = malloc (count_lines(mapname) * sizeof(char *) + 1);
	if (hold == NULL)
		return (NULL);
	i = 0;
	while (i < count_lines(mapname))
	{
		hold[i] = get_next_line(fd);
		if (hold[i] == NULL)
		{
			memmory_free(hold, i);
			return (NULL);
		}
		i++;
	}
	hold[i] = NULL;
	return (close(fd), hold);
}

int	starting_ending_colect_checker(char **hold, char *mapname)
{
	int		i;
	int		j;
	char	a[2];
	int		c;

	a[0] = '0';
	a[1] = '0';
	i = -1;
	c = 0;
	while (++i < count_lines (mapname))
	{
		j = 0;
		while (hold[i][j] != '\0')
		{
			if (hold[i][j] == 'P')
				a[0] += 1;
			if (hold[i][j] == 'E')
				a[1] += 1;
			if (hold[i][j++] == 'C')
				c += 1;
		}
	}
	if (a[0] == '1' && a[1] == '1' && c >= 1)
		return (1);
	return (0);
}

int	player_position_i(char **hold, char *mapname, char c)
{
	int	i;
	int	j;

	if (hold == NULL)
		return (0);
	i = 0;
	while (i < count_lines (mapname))
	{
		j = 0;
		while (hold[i][j] != '\0')
		{
			if (hold[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	player_position_j(char **hold, char *mapname, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < count_lines (mapname))
	{
		j = 0;
		while (hold[i][j] != '\0')
		{
			if (hold[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

char	**flood(char **hold, int i, int j)
{
	if (i < 0 || j < 0 || j >= ft_strlen(hold[i]))
		return (hold);
	else if (hold[i][j] == 'E')
		hold[i][j] = '*';
	else if (hold[i][j] == '0' || hold[i][j] == 'C' || hold[i][j] == 'E'
			|| hold[i][j] == 'P')
	{
		hold[i][j] = '*';
		flood(hold, i + 1, j);
		flood(hold, i, j + 1);
		flood(hold, i - 1, j);
		flood(hold, i, j - 1);
	}
	return (hold);
}
