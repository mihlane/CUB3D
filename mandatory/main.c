/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:46:36 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/03/31 07:51:07 by mhabibi-         ###   ########.fr       */
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

char    *get_fake_map(char *str, int k)
{
    char    *str2;
    int     i;

    i = 0;
    // printf("str --------- %s\n\n", str);
    str2 = malloc(sizeof(char) * (k + 1));
    while (i < k)
    {
        str2[i] =  '*';
        i++;
    }
    str2[i] = '\0';
    str = ft_strjoin(str, str2);
    // printf("%s\n", str);
    return (str);
}
int fk = 0;

void    check_char(char **map, int z, int i, t_cub *cub)
{
    if (map[z][i+1] != '1' && map[z][i+1] != '0' && map[z][i+1] != cub->player)
        print_error();
    if (map[z][i-1] != '1' && map[z][i-1] != '0' && map[z][i-1] != cub->player)
        print_error();
    if (map[z+1][i] != '1' && map[z+1][i] != '0' && map[z+1][i] != cub->player)
        print_error();
    if (map[z-1][i] != '1' && map[z-1][i] != '0' && map[z-1][i] != cub->player)
        print_error();
}

void    check_mapp(t_cub *cub, char **map, int z)
{
    int i;
    int k;

    // printf("str = %s\n\n", map[z]);
    fk++;
    if (cub->player != '*')
        return;
    k = ft_strlen(map[z]);
    i = z;
    z++;
    cub->nump = 0;
    while (map[z])
    {
        if ((int)ft_strlen(map[z]) > k)
            k = ft_strlen(map[z]);
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
    while(map[z])
    {
        i = 0;
        while (map[z][i])
        {
            if (map[z][i] == 'E' || map[z][i] == 'N' || map[z][i] == 'W' || map[z][i] == 'S')
            {
                if ( cub->player != '*' || cub->nump != 0)
                 print_error();
                cub->px = i;
                cub->py = z;
                cub->nump = 1;
                cub->player = map[z][i];
                // printf("x {%d}------ y {%d}-------- \n", cub->px, cub->py);
            }
            else if (map[z][i] != '0' && map[z][i] != '1' && map[z][i] != ' ')
                    print_error();
            i++;
        }
        z++;
    }
    i = k;
    while (map[i+1])
    {
        if ((int)ft_strlen(map[i]) < k)
            map[i] = get_fake_map(map[i], k - ft_strlen(map[i]));
        i++;
    }
    z = k;
    z++;
    while (map[z+1])
    {
        i = 0;
        printf("%s\n", map[z]);
        while (map[z][i])
        {
            if (map[z][i] == '0' || map[z][i] == cub->player)
            {
                printf("map= {%c}-----%d-----%d {%s}\n", map[z][i], z, i, map[z]);
                printf("salam\n");
                check_char(map, z, i, cub);
            }
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
    if (str[i] == '1' && cub->conditions != 0)
    {
        printf("sssss%d", cub->conditions);
        print_error();
    }
    // else
        
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
    i = 0;
    while (i < 3)
    {
        printf("%d       %d\n", cub->f[i], cub->c[i]);
        if ((cub->c[i] < 0 || cub->c[i] > 255)  || (cub->f[i] < 0 || cub->f[i] > 255))
            print_error();
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
void    ft_init(t_cub *cub)
{
    cub->north = NULL;
    cub->south = NULL;
    cub->east = NULL;
    cub->west = NULL;
    cub->player = '*';
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
    ft_init(cub);
    check_map(fd, av[1], cub);
}