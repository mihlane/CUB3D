/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:20:46 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/10 05:31:55 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing_Cub3d.h"

void	check_name(char *name)
{
	char	*str;
	int		i;
	char	*str2;

	str = ".cub";
	i = ft_strlen(name);
	i -= 4;
	str2 = ft_substr(name, i, ft_strlen(name) - i);
	if (ft_strcmp(str2, str) != 0)
		print_error("please try with valid name");
	free (str2);
}

char	*get_fake_map(char *str, int k)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = malloc(sizeof(char) * (k + 1));
	while (i < k)
	{
		str2[i] = '*';
		i++;
	}
	str2[i] = '\0';
	str = ft_strjoin(str, str2);
	free (str2);
	return (str);
}

void	check_char(char **map, int z, int i, t_cub *cub)
{
	if (map[z][i + 1] != '1' && map[z][i + 1] != '0' && map[z][i + 1]
	!= cub->player && map[z][i + 1] != cub->door)
		print_error("diffrent character in map");
	if (map[z][i - 1] != '1' && map[z][i - 1] != '0' && map[z][i - 1]
		!= cub->player && map[z][i - 1] != cub->door)
		print_error("diffrent character in map");
	if (map[z + 1][i] != '1' && map[z + 1][i] != '0' && map[z + 1][i]
		!= cub->player && map[z + 1][i] != cub->door)
		print_error("diffrent character in map");
	if (map[z - 1][i] != '1' && map[z - 1][i] != '0' && map[z - 1][i]
		!= cub->player && map[z - 1][i] != cub->door)
		print_error("diffrent character in map");
}

void	check_char2(char **map, int z, int i, t_cub *cub)
{
	int	k;

	k = 0;
	(void)cub;
	if (map[z][i + 1] == '1' && map[z][i - 1] == '1')
		k++;
	if (map[z + 1][i] == '1' && map[z - 1][i] == '1')
		k++;
	if (k == 0)
		print_error("door is not surrounded by walls");
}

int	get_max_len(char **map, int z, t_cub *cub)
{
	while (map[z])
	{
		if ((int)ft_strlen(map[z]) > cub->length)
			cub->length = ft_strlen(map[z]);
		else if (map[z][0] == '\n')
			print_error("there is new line inside map");
		z++;
	}
	return (cub->length);
}
