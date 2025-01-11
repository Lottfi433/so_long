/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:05 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/11 10:26:00 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	**hold;
	char	**copy;
	void	*mlx;
	void	*mlx_win;

	hold = NULL;
	hold = map_two_d(hold, "map.ber");
	copy = map_two_d(hold, "map.ber");
	if (parsing(hold) == 0)
	{
		write(1, "Fix your map", 12);
		exit(1);
	}
	free(hold);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	(void)mlx_win;
	mlx_loop(mlx);
	return (0);
}
