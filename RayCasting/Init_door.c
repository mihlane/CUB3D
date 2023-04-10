/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:19:01 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/10 09:22:35 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

t_door	new_door(int x, int y)
{
	t_door	obj;

	obj.x = x;
	obj.y = y;
	obj.dd_animated = -4;
	obj.range = 0;
	return (obj);
}

void	spots_doors(void)
{
	int	i;
	int	j;

	g_game.doors_size = 0;
	i = 0;
	while (i < g_game.map_width)
	{
		j = 0;
		while (j < g_game.map_height)
		{
			if (g_game.map[j][i] == DOOR)
				g_game.doors_size++;
			j++;
		}
		i++;
	}
	g_game.doors = (t_door *)malloc(sizeof(t_door) * g_game.doors_size);
}

void	init_doors(void)
{
	int	i;
	int	j;

	spots_doors();
	g_game.doors_size = 0;
	i = 0;
	while (i < g_game.map_width)
	{
		j = 0;
		while (j < g_game.map_height)
		{
			if (g_game.map[j][i] == DOOR)
				g_game.doors[g_game.doors_size++] = new_door(i, j);
			j++;
		}
		i++;
	}
	g_game.animated_door.img = mlx_xpm_file_to_image(g_game.mlx,
			"RayCasting/txt/door.xpm", &g_game.animated_door.w,
			&g_game.animated_door.h);
	if (!g_game.animated_door.img)
		end_game_error("Error : Door path must be: RayCasting/txt/door.xpm");
	g_game.animated_door.addr = mlx_get_data_addr(g_game.animated_door.img,
			&g_game.animated_door.bits_per_pixel,
			&g_game.animated_door.line_length, &g_game.animated_door.endian);
}

void	animate(void)
{
	int	i;

	i = -1;
	while (++i < g_game.doors_size)
	{
		if (g_game.doors[i].range + g_game.doors[i].dd_animated > (WALL_DIM / 2)
			- ANIMATED_DOOR
			OR g_game.doors[i].range + g_game.doors[i].dd_animated < 0)
			continue ;
		g_game.doors[i].range += g_game.doors[i].dd_animated;
	}
}
