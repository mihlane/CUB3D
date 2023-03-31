/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:34 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/03/31 07:42:23 by mhabibi-         ###   ########.fr       */
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

void    get_numbers(char **str, t_cub *cub)
{
    int i;
    int z;
    char *num;
    char *num2;
    
    i = 0;
    while (str[i])
    {
        z = 0;
        num = ft_strdup("");
        while (str[i][z])
        {
            if (str[i][z] != ' ' && (str[i][z] < '0' || str[i][z] > '9'))
                print_error();
            if  (str[i][z] == ' ')
                z++;
            else
            {
                num2 =  get_current_char_as_string(str[i][z]);
                num = ft_strjoin(num, num2);
                z++;
            }
        }
        cub->f[i] = ft_atoi(num);
        free(num);
        num = NULL;
        i++;
    }
}


void    check_floor(char *str, int i, t_cub *cub)
{
    char **str3;

    i++;
    cub->check = 0;
    if (str[i++] != ' ' && str[i++] != '\t')
        print_error();
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    // z = i;
    if (str[i] < 48 || str[i] > 57 )
        print_error();
    cub->camma = 0;
    // get_numbers(str, z, cub); 
    // cub->conditions -=5;
        
    str = ft_substr(str, i, ft_strlen(str) - i);
    str = ft_strtrim(str," ");
    str3 = ft_split(str, ',');
    int k = 0;
    while (str3[k])
        k++;
    if (k != 3)
            print_error();
    cub->camma = 0;
    get_numbers(str3, cub); 
    cub->conditions -=5;
    printf("ff = {%s}\n", str);
        // while (str[i])
        // {
        //     if (str[i] != ',' || (str[i] < 48 && str[i] > 57)  )
        //         print_error();
        //     i++;
        // }
    // (void)cub;
    // (void)i;
    // (void)str;
}

void    get_numbers2(char **str, t_cub *cub)
{
    int i;
    int z;
    char *num;
    char *num2;
    
    i = 0;
    while (str[i])
    {
        z = 0;
        num = ft_strdup("");
        while (str[i][z])
        {
            if (str[i][z] != ' ' && (str[i][z] < '0' || str[i][z] > '9'))
                print_error();
            if  (str[i][z] == ' ')
                z++;
            else
            {
                num2 =  get_current_char_as_string(str[i][z]);
                num = ft_strjoin(num, num2);
                z++;
            }
        }
        cub->c[i] = ft_atoi(num);
        printf("===========%d\n", cub->c[i]);
        free(num);
        num = NULL;
        i++;
    }
    i = 0;
    // while (cub->c[i])
    // {
    //     printf("===========%d\n", cub->c[i]);
    //     i++;
    // }
}

void    check_ceil(char *str, int i, t_cub *cub)
{
    i++;
    cub->check = 0;
    char **str3;
    if (str[i++] != ' ' && str[i++] != '\t')
        print_error();
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] < 48 || str[i] > 57 )
        print_error();
    str = ft_substr(str, i, ft_strlen(str) - i);
    str = ft_strtrim(str," ");
    printf("{%s}\n", str);
    str3 = ft_split(str, ',');
    int k = 0;
    while (str3[k])
        k++;
    if (k != 3)
            print_error();
    cub->camma = 0;
    get_numbers2(str3, cub); 
    cub->conditions -=6;
    // (void)cub;
    // (void)i;
    // (void)str;
}