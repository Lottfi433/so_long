/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_untils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:29:59 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/11 09:27:26 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				if (hold[i][j] != '1' && hold [i][j] != '*'
					&& hold[i][j] != '0')
					return (0);
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}
