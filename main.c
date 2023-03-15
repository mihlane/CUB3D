/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:46:36 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/03/14 14:50:32 by mhabibi-         ###   ########.fr       */
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
    str2 = ft_substr(name, i, ft_strlen(name) - i);
    i -=5;
	if (ft_strcmp(str2, str) != 0)
    {
        printf("str =={%s} str2 == {%s}, {%d}\n", str2, str, i);
		print_error();
    }
	// else
	// {
	// 	write(1, "map not valid\n", 15);
	// 	exit(1);
	// }
	// return (0);
}

void    check_map(int fd, char * name)
{
    char    *str;
    char    **map;

    check_name(name);
    str = get_next_line(fd);
    map = ft_split(str, '\n');
}

void    print_error(void)
{
    printf("error\n");
    exit(0);
}

int main(int ac, char**av)
{
    int fd;
    if (ac != 2)
        print_error();
    fd = open(av[1], O_RDONLY, 0777); 
    if (fd < 0)
        print_error();
    check_map(fd, av[1]);
}