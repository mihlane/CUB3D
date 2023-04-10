/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:52:24 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 14:35:32 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	update_view_angle(void)
{
	if (g_game.keys[LEFT_VIEW])
	{
		g_game.p.view_angle -= ROTATE_SPEED;
		if (g_game.p.view_angle < 0)
			g_game.p.view_angle += 2 * M_PI;
	}
	if (g_game.keys[RIGHT_VIEW])
	{
		g_game.p.view_angle += ROTATE_SPEED;
		if (g_game.p.view_angle > 2 * M_PI)
			g_game.p.view_angle -= 2 * M_PI;
	}
}

void	update_mouse(void)
{
	double	_dist;

	if (g_game.mouse.valid <= 1)
	{
		g_game.mouse.prev_x = g_game.mouse.curr_x;
		return ;
	}
	_dist = dist(g_game.mouse.prev_x, 0, g_game.mouse.curr_x, 0);
	if (g_game.mouse.prev_x > g_game.mouse.curr_x)
		g_game.p.view_angle -= (_dist * DR * 180) / SCREEN_WIDTH;
	else
		g_game.p.view_angle += (_dist * DR * 180) / SCREEN_WIDTH;
	if (g_game.p.view_angle > 2 * M_PI)
		g_game.p.view_angle -= 2 * M_PI;
	else if (g_game.p.view_angle < 0)
		g_game.p.view_angle += 2 * M_PI;
	g_game.mouse.prev_x = g_game.mouse.curr_x;
	g_game.mouse.valid--;
}

int	update(void)
{
	animate();
	update_mouvement();
	update_view_angle();
	update_mouse();
	raycasting();
	mlx_clear_window(g_game.mlx, g_game.mlx_game_win);
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_game_win,
		g_game.mlx_game_img.img, 0, 0);
	return (0);
}
