/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:38:48 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/11 10:08:41 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	one_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	one_checker2(char **hold, int lines)
{
	int	i;
	int	str_len;

	i = 0;
	while (i < lines)
	{
		str_len = ft_strlen(hold[i]);
		if (hold[i][0] != '1' || hold[i][str_len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	memmory_free(char **hold, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(hold[i]);
		i++;
	}
	free(hold);
}

int	map_checker(char *mapname)
{
	int		lines;
	int		i;
	int		fd;
	char	**hold;

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
	if (lines > 2 && one_checker(hold[lines - 1]) == 1
		&& one_checker(hold[0]) == 1 && one_checker2(hold, lines) == 1)
		return (1);
	close(fd);
	return (0);
}

int	parsing(char **hold)
{
	int	i;
	int	j;

	i = player_position_i(hold, "map.ber");
	j = player_position_j(hold, "map.ber");
	if (starting_ending_colect_checker(hold, "map.ber") == 1
		&& last_map_checking(flood(hold, i, j), "map.ber") == 1)
		return (1);
	return (0);
}
