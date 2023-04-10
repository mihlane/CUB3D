/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:00:03 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/08 18:25:29 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

t_door	*get_door(int x, int y)
{
	int	i;

	i = -1;
	while (++i < g_game.doors_size)
	{
		if (g_game.doors[i].x == x AND g_game.doors[i].y == y)
			return (&g_game.doors[i]);
	}
	return (NULL);
}

int	player_zone(t_door *door)
{
	int	player_map_x;
	int	player_map_y;

	player_map_x = g_game.p.x / WALL_DIM;
	player_map_y = g_game.p.y / WALL_DIM;
	return ((player_map_x == door->x
			AND (player_map_y + 1 == door->y OR player_map_y - 1 == door->y))
		OR (player_map_y == door->y
			AND (player_map_x + 1 == door->x OR player_map_x - 1 == door->x)));
}

double	dist(double ax, double ay, double bx, double by)
{
	return (hypot(ax - bx, ay - by));
}

unsigned int	get_color(int x, int y)
{
	char	*dst;
	t_data	*data;

	data = g_game.cast.curr_txt;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	check_player_zone(void)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < 360)
	{
		x = g_game.p.x + cos(i * M_PI / 180) * 5;
		y = g_game.p.y + sin(i * M_PI / 180) * 5;
		if (g_game.map[(int)y / WALL_DIM][(int)x / WALL_DIM] == WALL)
			return (0);
		i++;
	}
	return (1);
}
