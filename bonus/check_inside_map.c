/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:25:51 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/09 17:43:22 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	check_inside_map(char **map, t_cub *cub, int z, int k)
{
	int	i;

	while (map[z])
	{
		i = 0;
		while (map[z][i])
		{
			if (map[z][i] == 'E' || map[z][i] == 'N'
				|| map[z][i] == 'W' || map[z][i] == 'S')
			{
				if (cub->player != '*' || cub->nump != 0)
					print_error();
				cub->start = k + 1;
				cub->px = i;
				cub->py = z;
				cub->nump = 1;
				cub->player = map[z][i];
			}
			else if (map[z][i] != '0' && map[z][i] != '1'
				&& map[z][i] != ' ' && map[z][i] != cub->door)
				print_error();
			i++;
		}
		z++;
	}
}

char	**get_fm(char **map, t_cub *cub, int i)
{
	while (map[i + 1])
	{
		if ((int)ft_strlen(map[i]) < cub->length)
			map[i] = get_fake_map(map[i], cub->length - ft_strlen(map[i]));
		i++;
	}
	return (map);
}

void	check_last_line(char **map, int z)
{
	int	i;

	while (map[z])
	{
		i = 0;
		while (map[z][i])
		{
			if (map[z][i] != ' ' && map[z][i] != '1' && map[z][i] != '*')
				print_error();
			i++;
		}
		z++;
	}
}

void	check_inside_map2(char **map, int z, t_cub *cub)
{
	int	i;

	while (map[z + 1])
	{
		i = 0;
		while (map[z][i])
		{
			if (map[z][i] == '0' || map[z][i] == cub->player)
			{
				check_char(map, z, i, cub);
			}
			if (map[z][i] == cub->door)
				check_char2(map, z, i, cub);
			i++;
		}
		z++;
	}
	check_last_line(map, z);
}

void	check_mapp(t_cub *cub, char **map, int z)
{
	int	i;
	int	k;

	cub->length = ft_strlen(map[z]);
	cub->width = cub->n_lines - z;
	cub->map2 = malloc(sizeof(char *) * cub->width);
	i = z;
	z++;
	cub->nump = 0;
	cub->length = get_max_len(map, z, cub);
	i--;
	z = i;
	k = z;
	z++;
	check_inside_map(map, cub, z, k);
	i = k;
	map = get_fm(map, cub, i);
	z = k;
	z++;
	check_inside_map2(map, z, cub);
	cub->conditions--;
}
