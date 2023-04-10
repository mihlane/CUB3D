/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Horizontal_Dist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:44:33 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 08:39:02 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	get_horizontal_dist(int x_map, int y_map)
{
	g_game.cast.h_x = g_game.cast.x;
	g_game.cast.h_y = g_game.cast.y;
	g_game.cast.h_dist = dist(g_game.p.x, g_game.p.y,
			g_game.cast.h_x, g_game.cast.h_y);
	g_game.cast.type_collision_h = g_game.map[y_map][x_map];
}

int	check_horizontal_dist(int x_map, int y_map)
{
	double	pos_x;
	t_door	*curr_door;

	if (g_game.map[y_map][x_map] == WALL)
	{
		get_horizontal_dist(x_map, y_map);
		return (1);
	}
	else if (g_game.map[y_map][x_map] == DOOR)
	{
		pos_x = g_game.cast.x
			- ((int)g_game.cast.x - (int)g_game.cast.x % WALL_DIM);
		curr_door = get_door(x_map, y_map);
		if (pos_x >= (WALL_DIM / 2) + curr_door->range
			OR pos_x <= (WALL_DIM / 2) - curr_door->range)
		{
			get_horizontal_dist(x_map, y_map);
			return (1);
		}
		else if (dist(g_game.p.x, g_game.p.y,
				g_game.cast.x, g_game.cast.y) <= DOOR_OPEN_DIST)
			get_door(g_game.cast.x / WALL_DIM,
				g_game.cast.y / WALL_DIM)->dd_animated = ANIMATED_DOOR;
	}
	return (0);
}

void	find_horizontal_dist(void)
{
	int		x_map;
	int		y_map;

	while (g_game.cast.x >= 0.0 AND g_game.cast.y >= 0.0
		AND g_game.cast.x < g_game.dim_x AND g_game.cast.y < g_game.dim_y)
	{
		x_map = (int)g_game.cast.x / WALL_DIM;
		y_map = (int)g_game.cast.y / WALL_DIM;
		if (check_horizontal_dist(x_map, y_map))
			return ;
		g_game.cast.x += g_game.cast.dx;
		g_game.cast.y += g_game.cast.dy;
	}
	g_game.cast.h_dist = dist(0, 0, g_game.dim_x, g_game.dim_y);
}

void	horizontal_dist(double ray_angle)
{
	double	tn_angle;

	if (ray_angle == M_PI OR ray_angle == 0)
		return ;
	tn_angle = tan(ray_angle);
	if (ray_angle > M_PI)
	{
		g_game.cast.y = (((int)g_game.p.y
					- (int)g_game.p.y % WALL_DIM)) - 0.0001;
		g_game.cast.x = (g_game.cast.y - g_game.p.y) / tn_angle + g_game.p.x;
		g_game.cast.dy = -WALL_DIM;
		g_game.cast.dx = (g_game.cast.dy / tn_angle);
	}
	else
	{
		g_game.cast.y = (((int)g_game.p.y
					- (int)g_game.p.y % WALL_DIM)) + WALL_DIM;
		g_game.cast.x = (g_game.cast.y - g_game.p.y) / tn_angle + g_game.p.x;
		g_game.cast.dy = WALL_DIM;
		g_game.cast.dx = (g_game.cast.dy / tn_angle);
	}
	find_horizontal_dist();
}
