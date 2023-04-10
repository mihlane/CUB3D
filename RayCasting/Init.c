/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:02:48 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 13:49:23 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	init_textures_imgs(void)
{
	g_game.txt._n.img = mlx_xpm_file_to_image(g_game.mlx,
			g_game.texters_path[0],
			&g_game.txt._w.w,
			&g_game.txt._w.h);
	g_game.txt._s.img = mlx_xpm_file_to_image(g_game.mlx,
			g_game.texters_path[1],
			&g_game.txt._s.w,
			&g_game.txt._s.h);
	g_game.txt._w.img = mlx_xpm_file_to_image(g_game.mlx,
			g_game.texters_path[2],
			&g_game.txt._e.w,
			&g_game.txt._e.h);
	g_game.txt._e.img = mlx_xpm_file_to_image(g_game.mlx,
			g_game.texters_path[3],
			&g_game.txt._n.w,
			&g_game.txt._n.h);
	if (!g_game.txt._n.img OR !g_game.txt._s.img
		OR !g_game.txt._e.img OR !g_game.txt._w.img)
		end_game_error("Error : Cannot transfer to image !!");
}

void	init_textures_adds(void)
{
	g_game.txt._w.addr = mlx_get_data_addr(g_game.txt._w.img,
			&g_game.txt._w.bits_per_pixel,
			&g_game.txt._w.line_length,
			&g_game.txt._w.endian);
	g_game.txt._s.addr = mlx_get_data_addr(g_game.txt._s.img,
			&g_game.txt._s.bits_per_pixel,
			&g_game.txt._s.line_length,
			&g_game.txt._s.endian);
	g_game.txt._e.addr = mlx_get_data_addr(g_game.txt._e.img,
			&g_game.txt._e.bits_per_pixel,
			&g_game.txt._e.line_length,
			&g_game.txt._e.endian);
	g_game.txt._n.addr = mlx_get_data_addr(g_game.txt._n.img,
			&g_game.txt._n.bits_per_pixel,
			&g_game.txt._n.line_length,
			&g_game.txt._n.endian);
}

void	init_player(int x, int y, char dir)
{
	g_game.p.x = x * WALL_DIM + (WALL_DIM / 2);
	g_game.p.y = y * WALL_DIM + (WALL_DIM / 2);
	if (dir == NORTH_VIEW)
		g_game.p.view_angle = (3 * M_PI) / 2;
	else if (dir == SOUTH_VIEW)
		g_game.p.view_angle = M_PI_2;
	else if (dir == EAST_VIEW)
		g_game.p.view_angle = 0;
	else
		g_game.p.view_angle = M_PI;
}

void	init_game(void)
{
	g_game.mlx = mlx_init();
	init_textures_imgs();
	init_textures_adds();
	g_game.mlx_game_win = mlx_new_window(g_game.mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "CubGame");
	g_game.mlx_game_img.img = mlx_new_image(g_game.mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	g_game.mlx_game_img.addr = mlx_get_data_addr(g_game.mlx_game_img.img,
			&g_game.mlx_game_img.bits_per_pixel,
			&g_game.mlx_game_img.line_length,
			&g_game.mlx_game_img.endian);
	init_doors();
	g_game.mouse.valid = 0;
}
