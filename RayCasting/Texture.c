/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:29:55 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 14:03:00 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	get_texture_side(double ang)
{
	if (g_game.cast.type_collision == DOOR)
	{
		g_game.cast.curr_txt = &g_game.animated_door;
		return ;
	}
	if (g_game.cast.dir == VERTICAL)
	{
		if (ang >= M_PI_2 AND ang <= (3 * M_PI) / 2)
			g_game.cast.curr_txt = &g_game.txt._e;
		else
			g_game.cast.curr_txt = &g_game.txt._w;
	}
	else
	{
		if (ang >= 0 AND ang <= M_PI)
			g_game.cast.curr_txt = &g_game.txt._n;
		else
			g_game.cast.curr_txt = &g_game.txt._s;
	}
}

void	project_texture_verti(int px, double trn_of, double wall_h, int ray)
{
	int	txt_x;
	int	txt_y;

	if (g_game.cast.type_collision == DOOR)
	{
		if (g_game.cast.y <= (WALL_DIM / 2) - g_game.door_verti->range)
			txt_x = floor(((g_game.cast.y + g_game.door_verti->range)
						* g_game.cast.curr_txt->w) / WALL_DIM);
		else
			txt_x = floor(((g_game.cast.y - g_game.door_verti->range)
						* g_game.cast.curr_txt->w) / WALL_DIM);
	}
	else
		txt_x = floor(((g_game.cast.y) * g_game.cast.curr_txt->w) / WALL_DIM);
	txt_y = floor(((double)px + trn_of) * g_game.cast.curr_txt->h / wall_h);
	my_mlx_pixel_put(&g_game.mlx_game_img, ray,
		(SCREEN_HEIGHT / 2) - min(wall_h, SCREEN_HEIGHT) / 2 + px,
		get_color(txt_x, txt_y));
}

void	project_texture_horiz(int px, double trn_of, double wall_h, int ray)
{
	int	txt_x;
	int	txt_y;

	if (g_game.cast.type_collision == DOOR)
	{
		if (g_game.cast.x <= (WALL_DIM / 2) - g_game.door_horizo->range)
			txt_x = floor(((g_game.cast.x + g_game.door_horizo->range)
						* g_game.cast.curr_txt->w) / WALL_DIM);
		else
			txt_x = floor(((g_game.cast.x - g_game.door_horizo->range)
						* g_game.cast.curr_txt->w) / WALL_DIM);
	}
	else
		txt_x = floor(((g_game.cast.x) * g_game.cast.curr_txt->w) / WALL_DIM);
	txt_y = floor(((double)px + trn_of) * g_game.cast.curr_txt->h / wall_h);
	my_mlx_pixel_put(&g_game.mlx_game_img, ray,
		(SCREEN_HEIGHT / 2) - min(wall_h, SCREEN_HEIGHT) / 2 + px,
		get_color(txt_x, txt_y));
}

void	project_texture(int px, double trn_of, double wall_h, int ray)
{
	g_game.cast.x = g_game.cast.x
		- ((int)g_game.cast.x - (int)g_game.cast.x % WALL_DIM);
	g_game.cast.y = g_game.cast.y
		- ((int)g_game.cast.y - (int)g_game.cast.y % WALL_DIM);
	if (g_game.cast.dir)
		project_texture_horiz(px, trn_of, wall_h, ray);
	else
		project_texture_verti(px, trn_of, wall_h, ray);
}
