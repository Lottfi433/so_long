/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:08:54 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/11 09:35:02 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_two_d(char **hold, char *mapname) //this is for 2d array
{
	int	lines;
	int	i;
	int	fd;

	lines = count_lines(mapname);
	fd = open (mapname, O_RDWR);
	if (fd < 0)
		return (0);
	hold = malloc (lines * sizeof(char *));
	if (hold == NULL)
		return (0);
	i = 0;
	while (i < lines)
	{
		hold[i] = get_next_line(fd);
		if (hold[i] == NULL)
			memmory_free(hold, i);
		i++;
	}
	return (hold);
}

int	starting_ending_colect_checker(char **hold, char *mapname)//P C E check
{
	int		i;
	int		j;
	char	a[3];

	a[0] = '0';
	a[1] = '0';
	a[2] = '0';
	i = 0;
	while (i < count_lines (mapname))
	{
		j = 0;
		while (hold[i][j] != '\0')
		{
			if (hold[i][j] == 'P')
				a[0] += 1;
			if (hold[i][j] == 'E')
				a[1] += 1;
			if (hold[i][j++] == 'C')
				a[2] += 1;
		}
		i++;
	}
	if (a[0] == '1' && a[1] == '1' && a[2] >= '1')
		return (1);
	return (0);
}

int	player_position_i(char **hold, char *mapname)//to get P line
{
	int	i;
	int	j;

	i = 0;
	while (i < count_lines (mapname))
	{
		j = 0;
		while (hold[i][j] != '\0')
		{
			if (hold[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	player_position_j(char **hold, char *mapname)//to get P colone
{
	int	i;
	int	j;

	i = 0;
	while (i < count_lines (mapname))
	{
		j = 0;
		while (hold[i][j] != '\0')
		{
			if (hold[i][j] == 'P')
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
	else if (hold[i][j] != '1' && hold[i][j] != '*')
	{
		hold[i][j] = '*';
		flood(hold, i + 1, j);
		flood(hold, i, j + 1);
		flood(hold, i - 1, j);
		flood(hold, i, j - 1);
	}
	return (hold);
}
