/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:54:05 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/13 12:01:45 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	**hold;
	//char	**map;
	char	**copy;
	void	*mlx;
	void	*mlx_win;
	void	*img_bg;
	void	*walls_img;
	void	*player_img;
	void	*collect_img;
	int		height;
	int		width;
	int		map_h;
	int		map_w;


	copy = NULL;
	hold = NULL;
	hold = map_two_d(hold, "map.ber");
	copy = map_two_d(hold, "map.ber");
	map_w = ft_strlen(hold[0]);

	map_h = count_lines("map.ber");
	printf ("[%d] [%d]\n", map_h, map_w);
	if (parsing(hold) == 0)
	{
		write(1, "Fix your map", 12);
		exit(1);
	}
	free(hold);
	mlx = mlx_init();
	img_bg = mlx_xpm_file_to_image(mlx, "background.xpm", &width, &height);
	mlx_win = mlx_new_window(mlx, map_w * TILE_SIZE, map_h * TILE_SIZE, "Hello world!");

	walls_img = mlx_xpm_file_to_image(mlx, "wallimg.xpm", &width, &height);
	collect_img = mlx_xpm_file_to_image(mlx, "collect.xpm", &width, &height);
	player_img = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img_bg, 0, 0);
	int i = 0;
	int j;
	while (copy[i] != NULL)
	{
		j = 0;
		while (copy[i][j] != '\0')
		{
			if (copy[i][j] == '1')
			mlx_put_image_to_window(mlx, mlx_win, walls_img,TILE_SIZE * j, TILE_SIZE * i);
			if (copy[i][j] == 'P')
			mlx_put_image_to_window(mlx, mlx_win, player_img,TILE_SIZE * j, TILE_SIZE * i);
			if (copy[i][j] == 'C')
			mlx_put_image_to_window(mlx, mlx_win, collect_img,TILE_SIZE * j, TILE_SIZE * i);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
