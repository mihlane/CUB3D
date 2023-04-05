/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:34 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/04 21:50:19 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	check_north(char *str, int i, t_cub *cub)
{
	char	*north;
	int		fd;

	if (cub->north != NULL)
		print_error();
	i++;
	if (str[i] != 'O' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	north = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(north, O_RDONLY, 0777);
	// if (fd < 0)
	//     print_error();
	cub->north = north;
	cub->conditions -= 1;
}

void	check_south(char *str, int i, t_cub *cub)
{
	char	*south;
	int		fd;

	if (cub->south != NULL)
		print_error();
	i++;
	if (str[i] != 'O' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	south = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(south, O_RDONLY, 0777);
	// if (fd < 0)
	//     print_error();
	cub->south = south;
	cub->conditions -= 2;
}

void	check_west(char *str, int i, t_cub *cub)
{
	char	*west;
	int		fd;

	if (cub->west != NULL)
		print_error();
	i++;
	if (str[i] != 'E' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	west = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(west, O_RDONLY, 0777);
	// if (fd < 0)
	//     print_error();
	cub->west = west;
	cub->conditions -= 3;
}

void	check_east(char *str, int i, t_cub *cub)
{
	char	*east;
	int		fd;

	if (cub->east != NULL)
		print_error();
	i++;
	if (str[i] != 'A' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	east = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(east, O_RDONLY, 0777);
	// if (fd < 0)
	//     print_error();
	cub->east = east;
	cub->conditions -= 4;
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

void	get_numbers(char **str, t_cub *cub)
{
	int		i;
	int		z;
	char	*num;
	char	*num2;

	i = 0;
	while (str[i])
	{
		z = 0;
		num = ft_strdup("");
		while (str[i][z])
		{
			if (str[i][z] != ' ' && (str[i][z] < '0' || str[i][z] > '9'))
				print_error();
			if (str[i][z] == ' ')
				z++;
			else
			{
				num2 = get_current_char_as_string(str[i][z]);
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

void	check_floor(char *str, int i, t_cub *cub)
{
	char	**str3;
	int		k;

	i++;
	k = 0;
	cub->check = 0;
	if (str[i++] != ' ' && str[i++] != '\t')
		print_error();
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] < 48 || str[i] > 57)
		print_error();
	cub->camma = 0;
	str = ft_substr(str, i, ft_strlen(str) - i);
	str = ft_strtrim(str, " ");
	str3 = ft_split(str, ',');
	while (str3[k])
		k++;
	if (k != 3)
		print_error();
	cub->camma = 0;
	get_numbers(str3, cub);
	cub->conditions -= 5;
}

void	get_numbers2(char **str, t_cub *cub)
{
	int		i;
	int		z;
	char	*num;
	char	*num2;

	i = 0;
	while (str[i])
	{
		z = 0;
		num = ft_strdup("");
		while (str[i][z])
		{
			if (str[i][z] != ' ' && (str[i][z] < '0' || str[i][z] > '9'))
				print_error();
			if (str[i][z] == ' ')
				z++;
			else
			{
				num2 = get_current_char_as_string(str[i][z]);
				num = ft_strjoin(num, num2);
				z++;
			}
		}
		cub->c[i] = ft_atoi(num);
		free(num);
		num = NULL;
		i++;
	}
	i = 0;
}

void	check_ceil(char *str, int i, t_cub *cub)
{
	char	**str3;
	int		k;

	k = 0;
	i++;
	cub->check = 0;
	if (str[i++] != ' ' && str[i++] != '\t')
		print_error();
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] < 48 || str[i] > 57)
		print_error();
	str = ft_substr(str, i, ft_strlen(str) - i);
	str = ft_strtrim(str, " ");
	printf("{%s}\n", str);
	str3 = ft_split(str, ',');
	while (str3[k])
		k++;
	if (k != 3)
		print_error();
	cub->camma = 0;
	get_numbers2(str3, cub);
	cub->conditions -= 6;
}
