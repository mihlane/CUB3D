/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 08:35:46 by ychaaibi          #+#    #+#             */
/*   Updated: 2023/04/09 08:36:00 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	key_press(int keycode)
{	
	if (keycode == ESC)
		exit(0);
	if (keycode >= 125)
		return (0);
	g_game.keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode)
{
	if (keycode >= 125)
		return (0);
	g_game.keys[keycode] = 0;
	return (0);
}

int	mouse(int x, int y)
{
	if (x < 0 OR y < 0 OR x >= SCREEN_WIDTH OR y >= SCREEN_HEIGHT)
	{
		g_game.mouse.valid = 0;
		return (1);
	}
	g_game.mouse.curr_x = x;
	g_game.mouse.valid++;
	return (0);
}

int	end_game(void)
{
	exit(1);
	return (0);
}
