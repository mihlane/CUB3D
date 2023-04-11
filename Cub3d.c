/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:49:31 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 13:44:04 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RayCasting/Cub3d.h"
#include "Parsing/Parsing_Cub3d.h"

void	set_up_player(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_game.map_width)
	{
		j = -1;
		while (++j < g_game.map_height)
		{
			if (g_game.map[j][i] == WEST_VIEW
					OR g_game.map[j][i] == SOUTH_VIEW
					OR g_game.map[j][i] == NORTH_VIEW
					OR g_game.map[j][i] == EAST_VIEW)
			{
				init_player(i, j, g_game.map[j][i]);
				return ;
			}
		}	
	}
}

void	get_parse(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 125)
		g_game.keys[i] = 0;
	g_game.map = cub->map2;
	g_game.map_height = cub->width;
	g_game.map_width = cub->length;
	g_game.dim_x = g_game.map_width * WALL_DIM;
	g_game.dim_y = g_game.map_height * WALL_DIM;
	g_game.floor_color = cub->floor_color;
	g_game.ceiling_color = cub->ceiling_color;
	g_game.texters_path[0] = cub->textures[0];
	g_game.texters_path[1] = cub->textures[1];
	g_game.texters_path[2] = cub->textures[2];
	g_game.texters_path[3] = cub->textures[3];
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = parsing(ac, av);
	get_parse(cub);
	init_game();
	set_up_player();
	raycasting();
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_game_win,
		g_game.mlx_game_img.img, 0, 0);
	mlx_hook(g_game.mlx_game_win, KEY_PRESS_EVENT, 0, key_press, NULL);
	mlx_hook(g_game.mlx_game_win, KEY_RELEASE_EVENT, 0, key_release, NULL);
	mlx_hook(g_game.mlx_game_win, MOUSE_EVENT, 0, &mouse, NULL);
	mlx_hook(g_game.mlx_game_win, DESTROY_NOTIFY, 0, &end_game, NULL);
	mlx_loop_hook(g_game.mlx, update, NULL);
	mlx_loop(g_game.mlx);
	return (0);
}
