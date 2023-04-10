/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:46:36 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/10 09:16:10 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing_Cub3d.h"

void	check_col(char *str, t_cub *cub, char **map, int z)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] == 'N')
		check_north(str, i, cub);
	else if (str[i] == 'S')
		check_south(str, i, cub);
	else if (str[i] == 'W')
		check_west(str, i, cub);
	else if (str[i] == 'E')
		check_east(str, i, cub);
	else if (str[i] == 'F')
		check_floor(str, i, cub);
	else if (str[i] == 'C')
		check_ceil(str, i, cub);
	else if (str[i] == '1' && cub->conditions == 0)
		check_mapp(cub, map, z);
	else if (str[i] && str[i] != '\n')
		print_error("Wrong character");
}

void	check_colors(char **map, t_cub *cub)
{
	int	i;

	i = 0;
	cub->conditions = 21;
	while (map[i])
	{
		check_col(map[i], cub, map, i);
		if (cub->conditions == -1)
			break ;
		i++;
	}
	if (cub->conditions != -1)
		print_error("the map is not complete");
	i = 0;
	while (i < 3)
	{
		if ((cub->c[i] < 0 || cub->c[i] > 255)
			|| (cub->f[i] < 0 || cub->f[i] > 255))
			print_error("the rang of rgb is too high or too low");
		i++;
	}
}

void	check_lines(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	if (str[0] == '\n' && cub->line != 0)
		print_error("there is an empty line or the map is empty");
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '1')
		cub->line++;
}

void	check_map(int fd, char *name, t_cub *cub)
{
	char	*str;
	char	*buffer;

	buffer = ft_strdup("");
	cub->line = 0;
	check_name(name);
	while (1)
	{
		str = get_next_line(fd);
		if (str && str[0] != '\n')
			cub->n_lines++;
		if (str == NULL)
			break ;
		check_lines(str, cub);
		buffer = ft_strjoin(buffer, str);
		free (str);
	}
	cub->map = ft_split(buffer, '\n');
	free (buffer);
	check_colors(cub->map, cub);
}

t_cub	*parsing(int ac, char **av)
{
	t_cub	*cub;
	int		fd;

	if (ac != 2)
		print_error("try with two args");
	fd = open(av[1], O_RDONLY, 0777);
	if (fd < 0)
		print_error("file is inaccessible");
	cub = malloc(sizeof(t_cub));
	ft_init(cub);
	check_map(fd, av[1], cub);
	fill_map(cub);
	return (cub);
}
