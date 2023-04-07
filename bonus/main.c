/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:46:36 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/07 07:12:07 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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
		print_error();
	// free (str);
	// free (name);
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
		print_error();
	if (map[z][i - 1] != '1' && map[z][i - 1] != '0' && map[z][i - 1]
		!= cub->player && map[z][i - 1] != cub->door)
		print_error();
	if (map[z + 1][i] != '1' && map[z + 1][i] != '0' && map[z + 1][i]
		!= cub->player && map[z + 1][i] != cub->door)
		print_error();
	if (map[z - 1][i] != '1' && map[z - 1][i] != '0' && map[z - 1][i]
		!= cub->player && map[z - 1][i] != cub->door)
		print_error();
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
		print_error();
	// if (map[z][i+1] != '1' && map[z][i+1] != '0' && map[z][i+1] != cub->player)
	//     print_error();
	// if (map[z][i-1] != '1' && map[z][i-1] != '0' && map[z][i-1] != cub->player)
	//     print_error();
	// if (map[z+1][i] != '1' && map[z+1][i] != '0' && map[z+1][i] != cub->player)
	//     print_error();
	// if (map[z-1][i] != '1' && map[z-1][i] != '0' && map[z-1][i] != cub->player)
	//     print_error();
}

void	check_mapp(t_cub *cub, char **map, int z)
{
	int	i;
	int	k;
	int kh;
	if (cub->player != '*')
		return ;
	kh = ft_strlen(map[z]);
	i = z;
	z++;
	cub->nump = 0;
	while (map[z])
	{
		if ((int)ft_strlen(map[z]) > kh)
			kh = ft_strlen(map[z]);
		else if (map[z][0] == '\n')
		{
			print_error();
		}
		z++;
	}
	i--;
	z = i;
	k = z;
	z++;
	while (map[z])
	{
		i = 0;
		while (map[z][i])
		{
			if (map[z][i] == 'E' || map[z][i] == 'N'
				|| map[z][i] == 'W' || map[z][i] == 'S')
			{
				// if ( cub->player != '*' || cub->nump != 0)
				// {
				//  print_error();
				// }
				cub->px = i;
				cub->py = z;
				cub->nump = 1;
				cub->player = map[z][i];
				printf("x {%d}------ y {%d}-------- \n", cub->px, cub->py);
			}
			else if (map[z][i] != '0' && map[z][i] != '1'
				&& map[z][i] != ' ' && map[z][i] != cub->door)
				print_error();
			i++;
		}
		z++;
	}
	i = k;
	while (map[i + 1])
	{
		if ((int)ft_strlen(map[i]) < kh)
			map[i] = get_fake_map(map[i], kh - ft_strlen(map[i]));
		i++;
	}
	z = k;
	z++;
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
	// if (str[i] == '1' && cub->conditions != 0)
	// 	print_error();
}

void	check_colors(char **map, t_cub *cub)
{
	int	i;

	i = 0;
	cub->conditions = 21;
	while (map[i])
	{
		printf("%s\n", map[i]);
		check_col(map[i], cub, map, i);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if ((cub->c[i] < 0 || cub->c[i] > 255)
			|| (cub->f[i] < 0 || cub->f[i] > 255))
			print_error();
		i++;
	}
}

// void	check_new_l(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
		
// 	}
// }

void	check_lines(char *str, t_cub *cub)
{
	int i;

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
	char	**map;
	char	*buffer;

	buffer = ft_strdup("");
	cub->line = 0;
	check_name(name);
	while (1)
	{
		str = get_next_line(fd);
			// printf("%s",str);
		if (str == NULL)
			break;
		check_lines(str, cub);
		buffer = ft_strjoin(buffer,str);
	}
	// check_new_l(str);
	map = ft_split(buffer, '\n');
	check_colors(map, cub);
}

void	print_error(void)
{
	printf("error\n");
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
	// free (cub->north);
	// while (1);
}
