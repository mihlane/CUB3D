/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:34 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/03/31 02:08:09 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void    check_north(char *str, int i, t_cub *cub)
{
    char *north;
    int fd;
    

    if (cub->north != NULL)
        print_error();
    i++;
    if (str[i] != 'O' || (str[i+1] != ' ' && str[i+1] != '\t'))
        print_error();
    i+=2;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    north = ft_substr(str, i, ft_strlen(str) - i);
    fd = open(north, O_RDONLY, 0777); 
    // if (fd < 0)
    //     print_error();
    cub->north = north;
    cub->conditions -=1;
}

void    check_south(char *str, int i, t_cub *cub)
{
    char *south;
    int fd;
    
    if (cub->south != NULL)
        print_error();
    i++;
    // printf("%c", str[i]);
    if (str[i] != 'O' || (str[i+1] != ' ' && str[i+1] != '\t'))
        print_error();
    i+=2;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    south = ft_substr(str, i, ft_strlen(str) - i);
    fd = open(south, O_RDONLY, 0777); 
    // if (fd < 0)
    //     print_error();
    cub->south = south;
    cub->conditions -=2;
    // printf("south = {%s}\n", cub->south);
}

void    check_west(char *str, int i, t_cub *cub)
{
    char *west;
    int fd;

    if (cub->west != NULL)
        print_error();
    i++;
    if (str[i] != 'E' || (str[i+1] != ' ' && str[i+1] != '\t'))
        print_error();
    i+=2;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    west = ft_substr(str, i, ft_strlen(str) - i);
    fd = open(west, O_RDONLY, 0777); 
    // if (fd < 0)
    //     print_error();
    cub->west = west;
    cub->conditions -=3;
}

void    check_east(char *str, int i, t_cub *cub)
{
    char *east;
    int fd;

    if (cub->east != NULL)
        print_error();
    i++;
    if (str[i] != 'A' || (str[i+1] != ' ' && str[i+1] != '\t'))
        print_error();
    i+=2;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    east = ft_substr(str, i, ft_strlen(str) - i);
    fd = open(east, O_RDONLY, 0777); 
    // if (fd < 0)
    //     print_error();
    cub->east = east;
    cub->conditions -=4;
}

char	*get_current_char_as_string(char c)
{
	char	*str;

    if (c < 48 || c > 57)
        print_error();
	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void    get_numbers(char *str, int i, t_cub *cub)
{
    // int z;
    char *num;
    char *num2;
    num = ft_strdup("");
    while (str[i] && str[i] != ',' && str[i] != ' ')
    {
       num2 =  get_current_char_as_string(str[i]);
       num = ft_strjoin(num, num2);
       i++;
       if (str[i] == ',')
        cub->camma++;      
    }
        while (str[i] && str[i] == ' ')
            i++;
    if (cub->check < 3)
    {
        cub->f[cub->check] = ft_atoi(num);
        cub->check++;
            // if (i == (int)ft_strlen(str))
            //     break;
        if ( str[i++] != ',' && i < (int)ft_strlen(str))
        {
            printf("salam\n");
            print_error();
        }
        get_numbers(str, i, cub);
    }
    if (cub->camma != 2)
        print_error();
}

void    get_numbers2(char *str, int i, t_cub *cub)
{
 // int z;
    char *num;
    char *num2;
    num = ft_strdup("");
    while (str[i] && str[i] != ',' && str[i] != ' ')
    {
       num2 =  get_current_char_as_string(str[i]);
       num = ft_strjoin(num, num2);
       i++;
       if (str[i] == ',')
       {
        break;
        cub->camma++;    
       }  
    }
        while (str[i] && str[i] == ' ')
            i++;
    if (cub->check < 3)
    {
        cub->c[cub->check] = ft_atoi(num);
        cub->check++;
            // if (i == (int)ft_strlen(str))
            //     break;
        if ( str[i++] != ',' && i < (int)ft_strlen(str))
        {
            printf("salam\n");
            print_error();
        }
        get_numbers2(str, i, cub);
    }
    if (cub->camma != 2)
        print_error();
}

void    check_floor(char *str, int i, t_cub *cub)
{
    int z;

    i++;
    cub->check = 0;
    if (str[i++] != ' ' && str[i++] != '\t')
        print_error();
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    z = i;
    if (str[i] < 48 && str[i] > 57 )
        print_error();
        // while (str[i])
        // {
        //     if (str[i] != ',' || (str[i] < 48 && str[i] > 57)  )
        //         print_error();
        //     i++;
        // }
    cub->camma = 0;
    get_numbers(str, z, cub); 
    cub->conditions -=5;
    // (void)cub;
    // (void)i;
    // (void)str;
}

void    check_ceil(char *str, int i, t_cub *cub)
{
    i++;
    cub->check = 0;
    if (str[i++] != ' ' && str[i++] != '\t')
        print_error();
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] < 48 && str[i] > 57 )
        print_error();
        str = ft_substr(str, i, ft_strlen(str) - i);
        str = ft_strtrim(str," ");
        printf("{%s}\n", str);
    cub->camma = 0;
    get_numbers2(str, i, cub); 
    cub->conditions -=6;
    // (void)cub;
    // (void)i;
    // (void)str;
}