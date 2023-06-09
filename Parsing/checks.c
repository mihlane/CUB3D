/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:34 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/10 09:33:50 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing_Cub3d.h"

void	get_numbers(char **str, t_cub *cub)
{
	int		i;
	int		z;
	char	*num;

	i = 0;
	while (str[i])
	{
		z = 0;
		num = ft_strdup("");
		while (str[i][z])
		{
			if (str[i][z] != ' ' && (str[i][z] < '0' || str[i][z] > '9'))
				print_error("try with valid rgb numbers");
			while (str[i][z] == ' ')
				z++;
			while (str[i][z] >= '0' && str[i][z] <= '9')
				num = join_norm(num, str[i][z++]);
			while (str[i][z] == ' ')
				z++;
			if (str[i][z] && str[i][z] != ',')
				print_error("space inside rgb");
		}
		fill_and_free2(cub, num, i);
		i++;
	}
}

void	get_numbers2(char **str, t_cub *cub)
{
	int		i;
	int		z;
	char	*num;

	i = 0;
	while (str[i])
	{
		z = 0;
		num = ft_strdup("");
		while (str[i][z])
		{
			if (str[i][z] != ' ' && (str[i][z] < '0' || str[i][z] > '9'))
				print_error("try with valid rgb numbers");
			while (str[i][z] == ' ')
				z++;
			while (str[i][z] >= '0' && str[i][z] <= '9')
				num = join_norm(num, str[i][z++]);
			while (str[i][z] == ' ')
				z++;
			if (str[i][z] && str[i][z] != ',')
				print_error("space inside rgb");
		}
		fill_and_free(cub, num, i);
		i++;
	}
}

void	check_floor(char *str, int i, t_cub *cub)
{
	char	**str3;
	char	*str2;
	int		k;

	i++;
	k = 0;
	if (str[i++] != ' ' && str[i++] != '\t')
		print_error("floor rgb name is wrong");
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] < 48 || str[i] > 57)
		print_error("try with number only");
	cub->camma = 0;
	str2 = ft_substr(str, i, ft_strlen(str) - i);
	str = ft_strtrim(str2, " \t");
	check_camma(str);
	str3 = ft_split(str, ',');
	while (str3[k])
		k++;
	if (k != 3)
		print_error("there is more or less than tree numbers");
	cub->camma = 0;
	get_numbers(str3, cub);
	free_str(str3, str, str2, cub);
}

void	check_ceil(char *str, int i, t_cub *cub)
{
	char	**str3;
	char	*str2;
	int		k;

	k = 0;
	i++;
	if (str[i++] != ' ' && str[i++] != '\t')
		print_error("ceil rgb name is wrong");
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] < 48 || str[i] > 57)
		print_error("try with number only");
	cub->camma = 0;
	str2 = ft_substr(str, i, ft_strlen(str) - i);
	str = ft_strtrim(str2, " \t");
	check_camma(str);
	str3 = ft_split(str, ',');
	while (str3[k])
		k++;
	if (k != 3)
		print_error("there is more or less than tree numbers");
	cub->camma = 0;
	get_numbers2(str3, cub);
	free_str2(str3, str, str2, cub);
}
