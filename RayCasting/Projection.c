/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:28:58 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 14:39:05 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	project3d(double ray_angle, int ray)
{
	double	wall_height;
	int		px;
	double	tran_off;
	int		off;

	get_texture_side(ray_angle);
	g_game.cast.ray_dist *= cos(g_game.p.view_angle - ray_angle);
	wall_height = REAL_WALL_HEIGHT / g_game.cast.ray_dist;
	off = max(0, floor((SCREEN_HEIGHT / 2) - wall_height / 2));
	tran_off = max((wall_height - SCREEN_HEIGHT) / 2, 0);
	px = -1;
	while (++px < off)
		my_mlx_pixel_put(&g_game.mlx_game_img, ray, px, g_game.ceiling_color);
	px = -1;
	while (++px < min(wall_height, SCREEN_HEIGHT))
		project_texture(px, tran_off, wall_height, ray);
	px = off + wall_height;
	while (++px < SCREEN_HEIGHT)
		my_mlx_pixel_put(&g_game.mlx_game_img, ray, px,
			g_game.floor_color);
}
