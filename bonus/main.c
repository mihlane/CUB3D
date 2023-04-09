/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:46:36 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/09 17:45:42 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	check_col(char *str, t_cub *cub, char **map, int z)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] == 'N')
		check_north(str, i, cub);
	if (str[i] == 'S')
		check_south(str, i, cub);
	if (str[i] == 'W')
		check_west(str, i, cub);
	if (str[i] == 'E')
		check_east(str, i, cub);
	if (str[i] == 'F')
		check_floor(str, i, cub);
	if (str[i] == 'C')
		check_ceil(str, i, cub);
	if (str[i] == '1' && cub->conditions == 0)
		check_mapp(cub, map, z);
}

void	check_colors(char **map, t_cub *cub)
{
	int	i;

	i = 0;
	cub->conditions = 21;
	while (map[i])
	{
		check_col(map[i], cub, map, i);
		i++;
	}
	if (cub->conditions != -1)
		print_error();
	i = 0;
	while (i < 3)
	{
		if ((cub->c[i] < 0 || cub->c[i] > 255)
			|| (cub->f[i] < 0 || cub->f[i] > 255))
			print_error();
		i++;
	}
}

void	check_lines(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	if (str[0] == '\n' && cub->line != 0)
		print_error();
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

int	main(int ac, char**av)
{
	t_cub	*cub;
	int		fd;

	if (ac != 2)
		print_error();
	fd = open(av[1], O_RDONLY, 0777);
	if (fd < 0)
		print_error();
	cub = malloc(sizeof(t_cub));
	ft_init(cub);
	check_map(fd, av[1], cub);
	fill_map(cub);
}
