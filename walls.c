/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:38:48 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/23 09:37:45 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	one_checker(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\n')
		return (0);
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
	int	line_len;

	line_len = ft_strlen(hold[0]);
	i = 0;
	while (i < lines)
	{
		str_len = ft_strlen(hold[i]);
		if (hold[i][0] != '1' || hold[i][str_len - 1] != '1'
			|| ft_strlen(hold[i]) != line_len)
			return (0);
		i++;
	}
	return (1);
}

void	memmory_free(char **hold, int x)
{
	int	i;

	if (hold == NULL)
		return ;
	i = 0;
	while (i < x)
	{
		free(hold[i]);
		hold[i] = NULL;
		i++;
	}
	free(hold);
	hold = NULL;
}

int	map_checker(char *mapname)
{
	int		fd;
	char	**hold;

	fd = open (mapname, O_RDWR);
	if (fd < 0)
		return (0);
	hold = read_map(fd, mapname);
	if (count_lines(mapname) > 2
		&& one_checker(hold[count_lines(mapname) - 1]) == 1
		&& one_checker(hold[0]) == 1
		&& one_checker2(hold, count_lines(mapname)) == 1
		&& count_lines(mapname) != ft_strlen(hold[0]))
	{
		memmory_free(hold, count_lines(mapname));
		return (1);
	}
	memmory_free(hold, count_lines(mapname));
	return (0);
}

int	parsing(char **hold, char *mapname)
{
	int	i;
	int	j;

	if (hold == NULL)
		return (0);
	i = player_position_i(hold, mapname, 'P');
	j = player_position_j(hold, mapname, 'P');
	if (starting_ending_colect_checker(hold, mapname) == 1
		&& last_map_checking(flood(hold, i, j), mapname) == 1)
		return (1);
	write(1, "Fix your map", 12);
	return (0);
}
