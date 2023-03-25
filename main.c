/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:46:36 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/03/25 00:25:31 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void    check_name(char *name)
{
    char	*str;
    int     i;
    char    *str2;
	str = ".cub";
    i = ft_strlen(name);
    i -=4;
    str2 = ft_substr(name, i, ft_strlen(name) - i);
	if (ft_strcmp(str2, str) != 0)
		print_error();
	// else
	// {
	// 	write(1, "map not valid\n", 15);
	// 	exit(1);
	// }
	// return (0);
}

void    check_mapp(t_cub *cub, char **map, int z)
{
    int i;

    i = 0;
    cub->nump = 0;
    while(map[z])
    {
        while (map[z][i])
        {
            if (map[z][i] == 'E' || map[z][i] == 'N' || map[z][i] == 'W' || map[z][i] == 'S')
            {
                if (cub->nump != 0)
                    print_error();
                cub->px = i;
                cub->py = z;
                cub->nump = 1;
            }
            i++;
        }
        z++;
    }
}

void    check_col(char *str, t_cub *cub, char **map, int z)
{
    int i;

    i = 0;
    while (str[i] && ( str[i] == '\t' || str[i] == ' '))
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
    // else
    //     print_error();
        
}

void    check_colors(char **map, t_cub *cub)
{
    int i;

    i = 0;
    cub->conditions = 21;
    while(map[i])
    {
        check_col(map[i], cub, map, i);
        i++;
    }
}

void    check_map(int fd, char * name, t_cub *cub)
{
    char    *str;
    char    **map;

    check_name(name);
    str = get_next_line(fd);
    map = ft_split(str, '\n');
    check_colors(map,cub);
}

void    print_error(void)
{
    printf("error\n");
    exit(0);
}

int main(int ac, char**av)
{
    t_cub *cub;
    int fd;
    
    if (ac != 2)
        print_error();
    fd = open(av[1], O_RDONLY, 0777); 
    if (fd < 0)
        print_error();
    cub = malloc(sizeof(t_cub));
    check_map(fd, av[1], cub);
}