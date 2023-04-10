/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firs_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:57:11 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/10 07:51:35 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing_Cub3d.h"

void	check_first_line(char **map, int z)
{
	int	i;

	i = 0;
	z++;
	while (map[z][i])
	{
		if (map[z][i] != '1' && map[z][i] != ' ')
			print_error("please check first line of map");
		i++;
	}
}
