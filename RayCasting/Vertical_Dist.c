/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertical_Dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:43:13 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 08:39:17 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	get_vertical_dist(int x_map, int y_map)
{
	g_game.cast.v_x = g_game.cast.x;
	g_game.cast.v_y = g_game.cast.y;
	g_game.cast.v_dist = dist(g_game.p.x, g_game.p.y,
			g_game.cast.v_x, g_game.cast.v_y);
	g_game.cast.type_collision_v = g_game.map[y_map][x_map];
}

int	check_vertical_dist(int x_map, int y_map)
{
	double	pos_x;
	t_door	*curr_door;

	if (g_game.map[y_map][x_map] == WALL)
	{
		get_vertical_dist(x_map, y_map);
		return (1);
	}
	else if (g_game.map[y_map][x_map] == DOOR)
	{
		pos_x = g_game.cast.y
			- ((int)g_game.cast.y - (int)g_game.cast.y % WALL_DIM);
		curr_door = get_door(x_map, y_map);
		if (pos_x >= (WALL_DIM / 2) + curr_door->range
			OR pos_x <= (WALL_DIM / 2) - curr_door->range)
		{
			get_vertical_dist(x_map, y_map);
			return (1);
		}
		else if (dist(g_game.p.x, g_game.p.y,
				g_game.cast.x, g_game.cast.y) <= DOOR_OPEN_DIST)
			get_door(g_game.cast.x / WALL_DIM,
				g_game.cast.y / WALL_DIM)->dd_animated = ANIMATED_DOOR;
	}
	return (0);
}

void	find_vertical_dist(void)
{
	int		x_map;
	int		y_map;

	while (g_game.cast.x >= 0.0 AND g_game.cast.y >= 0.0 AND
		g_game.cast.x < g_game.dim_x AND g_game.cast.y < g_game.dim_y)
	{
		x_map = (int)g_game.cast.x / WALL_DIM;
		y_map = (int)g_game.cast.y / WALL_DIM;
		if (check_vertical_dist(x_map, y_map))
			return ;
		g_game.cast.x += g_game.cast.dx;
		g_game.cast.y += g_game.cast.dy;
	}
}

void	vertical_dist(double ray_angle)
{
	double	tn_angle;

	g_game.cast.v_dist = 100000000.0;
	if (ray_angle == M_PI_2 OR ray_angle == (3 * M_PI) / 2)
		return ;
	tn_angle = tan(ray_angle);
	if (ray_angle > M_PI_2 AND ray_angle < (3 * M_PI) / 2)
	{
		g_game.cast.x = (((int)g_game.p.x
					- (int)g_game.p.x % WALL_DIM)) - 0.0001;
		g_game.cast.y = (g_game.cast.x - g_game.p.x) * tn_angle + g_game.p.y;
		g_game.cast.dx = -WALL_DIM;
		g_game.cast.dy = g_game.cast.dx * tn_angle ;
	}
	else
	{
		g_game.cast.x = (((int)g_game.p.x
					- (int)g_game.p.x % WALL_DIM)) + WALL_DIM;
		g_game.cast.y = (g_game.cast.x - g_game.p.x) * tn_angle + g_game.p.y;
		g_game.cast.dx = WALL_DIM;
		g_game.cast.dy = g_game.cast.dx * tn_angle;
	}
	find_vertical_dist();
}
