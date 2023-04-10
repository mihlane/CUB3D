/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nd_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:24:42 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/10 09:14:44 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing_Cub3d.h"

void	print_error(char *str)
{
	write (2, "ERROR : ", 9);
	write(2, str, ft_strlen(str));
	write (2, ".\n", 2);
	exit(0);
}

void	ft_init(t_cub *cub)
{
	cub->north = NULL;
	cub->south = NULL;
	cub->east = NULL;
	cub->west = NULL;
	cub->player = '*';
	cub->door = '2';
	cub->n_lines = 0;
	cub->nump = 0;
	cub->c[0] = -1;
	cub->f[0] = -1;
}

void	fill_text(t_cub *cub)
{
	cub->textures = malloc(sizeof(char *) * 5);
	cub->textures[0] = cub->north;
	cub->textures[1] = cub->south;
	cub->textures[2] = cub->west;
	cub->textures[3] = cub->east;
	cub->textures[4] = NULL;
}

void	fill_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[cub->start])
	{
		cub->map2[i] = cub->map[cub->start];
		cub->start++;
		i++;
	}
	cub->map[i] = NULL;
	cub->ceiling_color = rgbtoint(cub->c[0], cub->c[1], cub->c[2]);
	cub->floor_color = rgbtoint(cub->f[0], cub->f[1], cub->f[2]);
	fill_text(cub);
}
