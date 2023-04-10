/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:26:49 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 14:35:25 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	cast_horizontal(void)
{
	g_game.cast.dir = HORIZONTAL;
	g_game.cast.x = g_game.cast.h_x;
	g_game.cast.y = g_game.cast.h_y;
	g_game.cast.ray_dist = g_game.cast.h_dist;
	g_game.cast.type_collision = g_game.cast.type_collision_h;
	if (g_game.cast.type_collision == DOOR)
	{
		g_game.door_horizo = get_door(g_game.cast.x / WALL_DIM,
				g_game.cast.y / WALL_DIM);
		if (g_game.cast.ray_dist <= DOOR_OPEN_DIST)
			g_game.door_horizo->dd_animated = ANIMATED_DOOR;
	}
}

void	cast_vertical(void)
{
	g_game.cast.dir = VERTICAL;
	g_game.cast.x = g_game.cast.v_x;
	g_game.cast.y = g_game.cast.v_y;
	g_game.cast.ray_dist = g_game.cast.v_dist;
	g_game.cast.type_collision = g_game.cast.type_collision_v;
	if (g_game.cast.type_collision == DOOR)
	{
		g_game.door_verti = get_door(g_game.cast.x / WALL_DIM,
				g_game.cast.y / WALL_DIM);
		if (g_game.cast.ray_dist <= DOOR_OPEN_DIST)
			g_game.door_verti->dd_animated = ANIMATED_DOOR;
	}
}

void	cast_rays_2d(int ray, double ray_angle)
{
	horizontal_dist(ray_angle);
	vertical_dist(ray_angle);
	if (g_game.cast.h_dist < g_game.cast.v_dist)
		cast_horizontal();
	else
		cast_vertical();
	project3d(ray_angle, ray);
}

void	update_doors(void)
{
	int	i;

	i = -1;
	while (++i < g_game.doors_size)
	{
		if (g_game.p.x / WALL_DIM == g_game.doors[i].x
			AND g_game.p.y / WALL_DIM == g_game.doors[i].y)
			g_game.doors[i].dd_animated = ANIMATED_DOOR;
		else
			g_game.doors[i].dd_animated = -ANIMATED_DOOR;
	}
}

void	raycasting(void)
{
	double	ray_angle;
	double	diff;
	int		ray;

	g_game.door_horizo = NULL;
	g_game.door_verti = NULL;
	ray_angle = g_game.p.view_angle - HFOV * DR;
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	diff = (FOV * DR) / SCREEN_WIDTH;
	ray = 0;
	update_doors();
	while (ray < SCREEN_WIDTH)
	{
		cast_rays_2d(ray, ray_angle);
		ray++;
		ray_angle += diff;
		if (ray_angle > 2 * M_PI)
			ray_angle -= 2 * M_PI;
	}
	mini_map();
}
