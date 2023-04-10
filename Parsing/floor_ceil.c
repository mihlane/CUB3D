/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:46:35 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/10 09:00:00 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing_Cub3d.h"

char	*get_current_char_as_string(char c)
{
	char	*str;

	if (c < 48 || c > 57)
		print_error("try with numbers only");
	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	check_camma(char *str)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (str[i])
	{
		if (str[i] == ',')
			z++;
		i++;
	}
	if (z != 2)
		print_error("there is more or less than three numbers");
}

void	free_str(char **str3, char *str, char *str2, t_cub *cub)
{
	int	k;

	k = 0;
	while (str3[k])
	{
		free (str3[k]);
		k++;
	}
	free(str3);
	free (str);
	free (str2);
	cub->conditions -= 5;
}

void	free_str2(char **str3, char *str, char *str2, t_cub *cub)
{
	int	k;

	k = 0;
	while (str3[k])
	{
		free (str3[k]);
		k++;
	}
	free(str3);
	free(str);
	free (str2);
	cub->conditions -= 6;
}

void	fill_and_free(t_cub *cub, char *num, int i)
{
	if (ft_strlen(num) > 3)
		print_error("rgb colors should be only three digits!!");
	if (i == 0 && cub->c[0] != -1)
		print_error("Ceil alredy cisited");
	cub->c[i] = ft_atoi(num);
	free(num);
	num = NULL;
}
