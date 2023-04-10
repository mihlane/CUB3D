/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:53:20 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 08:32:21 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	update_mouvement_horizontal(double speed_sin, double speed_cos)
{
	if (g_game.keys[RIGHT])
	{
		g_game.p.x -= speed_sin;
		g_game.p.y += speed_cos;
	}
	if (g_game.keys[LEFT])
	{
		g_game.p.x += speed_sin;
		g_game.p.y -= speed_cos;
	}
}

void	update_mouvement_vertical(double speed_sin, double speed_cos)
{
	if (g_game.keys[UP])
	{
		g_game.p.x += speed_cos;
		g_game.p.y += speed_sin;
	}
	if (g_game.keys[DOWN])
	{
		g_game.p.x -= speed_cos;
		g_game.p.y -= speed_sin;
	}
}

void	update_mouvement(void)
{
	double	speed_sin;
	double	speed_cos;
	double	prev_player_x;
	double	prev_player_y;

	speed_sin = sin(g_game.p.view_angle) * SPEED;
	speed_cos = cos(g_game.p.view_angle) * SPEED;
	prev_player_x = g_game.p.x;
	prev_player_y = g_game.p.y;
	update_mouvement_horizontal(speed_sin, speed_cos);
	update_mouvement_vertical(speed_sin, speed_cos);
	if (!check_player_zone())
	{
		g_game.p.x = prev_player_x;
		g_game.p.y = prev_player_y;
	}
}
