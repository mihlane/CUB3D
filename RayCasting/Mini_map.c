/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:22:29 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 08:42:16 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	mini_map_player(int x, int y)
{
	int	i;
	int	ang;

	ang = -31;
	while (++ang <= 30)
	{
		i = -1;
		while (++i < 13)
			my_mlx_pixel_put(&g_game.mlx_game_img,
				x + cos(g_game.p.view_angle + (ang * DR)) * i,
				y + sin(g_game.p.view_angle + (ang * DR)) * i,
				0xff0000);
	}
}

void	draw_mini_map(int i, int j, int player_x, int player_y)
{
	int		cast;
	double	_x;
	double	_y;

	cast = 0;
	_x = player_x + i;
	_y = player_y + j;
	if (_x / 20 >= 0 AND _y / 20 >= 0 AND _x / 20 < g_game.map_width
		AND _y / 20 < g_game.map_height
		AND g_game.map[(int)(_y / 20)][(int)(_x / 20)] == WALL)
		cast = 0XFFFFFF;
	else if (_x / 20 >= 0 AND _y / 20 >= 0 AND _x / 20 < g_game.map_width
		AND _y / 20 < g_game.map_height
		AND g_game.map[(int)(_y / 20)][(int)(_x / 20)] == DOOR)
		cast = 0XFF0000;
	if (dist(M_MPPX, M_MPPY, M_MPX + i, M_MPY + j) < 70)
		my_mlx_pixel_put(&g_game.mlx_game_img, M_MPX + i, M_MPY + j, cast);
	else if (dist(M_MPPX, M_MPPY, M_MPX + i, M_MPY + j) <= 75)
		my_mlx_pixel_put(&g_game.mlx_game_img, M_MPX + i, M_MPY + j, 0xffffff);
}

void	mini_map(void)
{
	double		player_x;
	double		player_y;
	int			i;
	int			j;

	player_x = (g_game.p.x * 20) / WALL_DIM - 75;
	player_y = (g_game.p.y * 20) / WALL_DIM - 75;
	i = -1;
	while (++i < 150)
	{
		j = -1;
		while (++j < 150)
			draw_mini_map(i, j, player_x, player_y);
	}
	mini_map_player(SCREEN_WIDTH - 75, SCREEN_HEIGHT - 75);
}
