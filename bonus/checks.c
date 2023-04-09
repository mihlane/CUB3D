/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:34 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/09 07:09:49 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"



char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	free (s2);
	return (str);
}

void	check_north(char *str, int i, t_cub *cub)
{
	char	*north;
	// int		fd;

	if (cub->north != NULL)
		print_error();
	i++;
	if (str[i] != 'O' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	north = ft_substr(str, i, ft_strlen(str) - i);
	// fd = open(north, O_RDONLY, 0777);
	// if (fd < 0)
	//     print_error();
	cub->north = north;
	free (north);
	cub->conditions -= 1;
}

void	check_south(char *str, int i, t_cub *cub)
{
	char	*south;
	// int		fd;

	if (cub->south != NULL)
		print_error();
	i++;
	if (str[i] != 'O' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	south = ft_substr(str, i, ft_strlen(str) - i);
	// fd = open(south, O_RDONLY, 0777);
	// if (fd < 0)
	//     print_error();
	cub->south = south;
	free (south);
	cub->conditions -= 2;
}

void	check_west(char *str, int i, t_cub *cub)
{
	char	*west;
	// int		fd;

	if (cub->west != NULL)
		print_error();
	i++;
	if (str[i] != 'E' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	west = ft_substr(str, i, ft_strlen(str) - i);
	// fd = open(west, O_RDONLY, 0777);
	// if (fd < 0)
	//     print_error();
	cub->west = west;
	free (west);
	cub->conditions -= 3;
}

void	check_east(char *str, int i, t_cub *cub)
{
	char	*east;
	// int		fd;

	if (cub->east != NULL)
		print_error();
	i++;
	if (str[i] != 'A' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	east = ft_substr(str, i, ft_strlen(str) - i);
	// fd = open(east, O_RDONLY, 0777);
	// if (fd < 0)
	//     print_error();
	cub->east = east;
	free (east);
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
				num = ft_strjoin2(num, num2);
				// free (num2);
				z++;
			}
		}
		cub->f[i] = ft_atoi(num);
		free(num);
		num = NULL;
		i++;
	}
		// free (cub->f);
}

void	check_camma(char *str)
{
	int i;
	int z;
	
	i = 0;
	z = 0;
	while (str[i])
	{
		if (str[i] == ',')
			z++;
		i++;
	}
	if (z != 2)
		print_error();
}

void	check_floor(char *str, int i, t_cub *cub)
{
	char	**str3;
	char	*str2;
	// char	*str4;
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
	str2 = ft_substr(str, i, ft_strlen(str) - i);
	str = ft_strtrim(str2, " ");
	check_camma(str);
	str3 = ft_split(str, ',');
	while (str3[k])
		k++;
	if (k != 3)
		print_error();
	cub->camma = 0;
	get_numbers(str3, cub);
	k = 0;
	// printf("%p\n%p\n%p\n", str, str2, str3)
	while (str3[k])
	{
		free (str3[k]);
		k++;
	}
	free(str3);
	free (str);
	free (str2);
	// free (str4);
	cub->conditions -= 5;
	// while (1);
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
				num = ft_strjoin2(num, num2);
				// free (num2);
				z++;
			}
		}
		cub->c[i] = ft_atoi(num);
		free(num);
		// printf("----------%d\n", cub->c[i]);
		num = NULL;
		i++;
	}
}


void	check_ceil(char *str, int i, t_cub *cub)
{
	char	**str3;
	char	*str2;
	char	*str4;
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
	str4 = ft_substr(str, i, ft_strlen(str) - i);
	str2 = ft_strtrim(str, " ");
	check_camma(str);
	str3 = ft_split(str4, ',');
	while (str3[k])
		k++;
	if (k != 3)
		print_error();
	cub->camma = 0;
	get_numbers2(str3, cub);
	k = 0;
	while (str3[k])
	{
		free (str3[k]);
		k++;
	}
	free (str3);
	free (str);
	free (str2);
	free (str4);
	// while (1);
	cub->conditions -= 6;
}
